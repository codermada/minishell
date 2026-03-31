/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_redirs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toloandr <toloandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 20:53:59 by toloandr          #+#    #+#             */
/*   Updated: 2025/08/08 21:34:37 by toloandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static void	dup_fd(int old_fd, int new_fd)
{
	if ((old_fd != new_fd) && (old_fd >= 0))
	{
		dup2(old_fd, new_fd);
		close(old_fd);
	}
}

static void	dup_redirs(t_list *chunk)
{
	t_list	*current;
	int		*type;
	int		*fd;

	current = chunk;
	while (current)
	{
		type = &((t_token *)current->data)->type;
		fd = &((t_token *)current->data)->fd;
		if (*type == INFILE)
			dup_fd(*fd, STDIN_FILENO);
		else if (*type == HEREDOC)
		{
			if (current->fd[0] >= 0)
				dup_fd(current->fd[0], STDIN_FILENO);
		}
		else if ((*type == OUTFILE) || (*type == APPEND))
			dup_fd(*fd, STDOUT_FILENO);
		current = current->next_;
	}
}

static void	path_not_found(char *pathname)
{
	put_str_fd(STDERR_FILENO, "minishell: ");
	perror(pathname);
}

static int	open_(char *pathname, int flags, mode_t mode, t_list *tokens)
{
	int	fd;

	if (str_len(pathname) == 0)
	{
		tokens->exit = -1;
		print_error_(pathname, "No such file or directory", 1);
		return (-1);
	}
	fd = open(pathname, flags, mode);
	if (fd == -1)
	{
		if (errno == EACCES || errno == EPERM)
			tokens->exit = -1;
		if (errno == ENOENT)
			tokens->exit = -1;
		else
			tokens->exit = -1;
		path_not_found(pathname);
		return (-1);
	}
	return (fd);
}

int	run_redirs(t_list *chunk)
{
	t_list	*current;
	t_token	*tok;
	t_token	*next_tok;
	int		flags;

	current = chunk;
	while (current)
	{
		tok = (t_token *)current->data;
		if (tok->type == INFILE || tok->type == OUTFILE || tok->type == APPEND)
		{
			next_tok = (t_token *)current->next->data;
			if (tok->type == INFILE)
				flags = O_RDONLY;
			else if (tok->type == OUTFILE)
				flags = O_CREAT | O_TRUNC | O_WRONLY;
			else
				flags = O_CREAT | O_APPEND | O_WRONLY;
			tok->fd = open_(next_tok->token, flags, 0644, chunk->head);
			if (tok->fd < 0)
				return (dup_redirs(chunk), 0);
		}
		current = current->next_;
	}
	return (dup_redirs(chunk), 1);
}
