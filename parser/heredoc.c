/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toloandr <toloandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 07:15:32 by toloandr          #+#    #+#             */
/*   Updated: 2025/08/02 22:56:30 by toloandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	close_fd_0_1(t_list *tokens)
{
	t_list	*current;
	int		*type;

	current = tokens;
	while (current)
	{
		type = &((t_token *)current->data)->type;
		if ((*type == HEREDOC) || (*type == PIPE))
		{
			if (current->fd[1] != -1)
				close(current->fd[1]);
			if (current->fd[0] != -1)
				close(current->fd[0]);
		}
		current = current->next;
	}
}

void	close_fd_1(t_list *tokens)
{
	t_list	*current;
	int		*type;

	current = tokens;
	while (current)
	{
		type = &((t_token *)current->data)->type;
		if (*type == HEREDOC)
		{
			if (current->fd[1] != -1)
				close(current->fd[1]);
		}
		current = current->next;
	}
}

void	pipe_heredocs(t_list *tokens)
{
	t_list	*current;
	int		*type;

	current = tokens;
	while (current)
	{
		type = &((t_token *)current->data)->type;
		if (*type == HEREDOC)
		{
			if (pipe(current->fd) == -1)
			{
				print_error("pipe error");
				return ;
			}
		}
		current = current->next;
	}
}

void	heredocs_in_subprocess(t_list *tokens)
{
	t_list	*current;
	int		*type;

	current = tokens;
	while (current)
	{
		type = &((t_token *)current->data)->type;
		if (*type == HEREDOC)
		{
			if (current->next)
				heredoc(current->fd[1], \
			((t_token *)current->next->data)->token, \
			&tokens, current->hd_delim_quoted);
			close(current->fd[0]);
			close(current->fd[1]);
		}
		current = current->next;
	}
	close(tokens->history_fd);
	close_fd_pipes(tokens);
	free_dict(tokens->env_dict, 1, 1);
	free_env(tokens->env);
	free(tokens->input);
	free_tokens(&tokens);
}

int	run_heredocs(t_list *tokens)
{
	pid_t	pid;
	int		status;

	pipe_heredocs(tokens);
	signal(SIGINT, SIG_IGN);
	pid = fork_1();
	if (pid == -1)
		return (1);
	if (pid == 0)
	{
		signal(SIGINT, heredoc_handle_sigint);
		heredocs_in_subprocess(tokens);
		exit(0);
	}
	while (wait(&status) > 0)
		;
	if (WIFEXITED(status))
	{
		if (WEXITSTATUS(status) == 130)
			close_fd_0_1(tokens);
		else
			close_fd_1(tokens);
	}
	return (WEXITSTATUS(status));
}
