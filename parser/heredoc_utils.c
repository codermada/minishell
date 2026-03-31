/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toloandr <toloandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 07:50:14 by toloandr          #+#    #+#             */
/*   Updated: 2025/08/04 20:23:33 by toloandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	heredoc_handle_sigint(int sig)
{
	t_list	*tokens;

	(void)sig;
	write(STDOUT_FILENO, "\n", 1);
	tokens = get_list(NULL);
	if (tokens)
	{
		close(tokens->history_fd);
		close_fd_pipes(tokens);
		close_fd_0_1(tokens);
		free_dict(tokens->env_dict, 1, 1);
		free_env(tokens->env);
		free(tokens->input);
		free_tokens(&tokens);
		exit(130);
	}
	exit(130);
}

void	null_input(char **input, t_list **tokens, char *delim)
{
	(void)tokens;
	if (!(*input))
	{
		print_error_("warning", \
" here-document delimited by end-of-file (wanted `", 0);
		put_str_fd(STDERR_FILENO, delim);
		put_str_fd(STDERR_FILENO, "')\n");
	}
}

void	heredoc(int fd, char *delim, t_list **tokens, int hd_delim_quoted)
{
	char	*input;
	char	*expanded;

	while (1)
	{
		input = readline("> ");
		null_input(&input, tokens, delim);
		if (!input)
			break ;
		if (str_cmp(delim, input) == 1)
			break ;
		if (hd_delim_quoted == 0)
		{
			expanded = expand_(input, *((*tokens)->env_dict));
			put_str_fd(fd, expanded);
			free(expanded);
		}
		else
			put_str_fd(fd, input);
		put_str_fd(fd, "\n");
		free(input);
	}
	free(input);
}

void	close_fd_pipes(t_list *tokens)
{
	t_list	*current;
	int		*type;

	current = tokens;
	while (current)
	{
		type = &((t_token *)current->data)->type;
		if (*type == PIPE)
		{
			if (current->fd[1] != -1)
			{
				close(current->fd[1]);
				current->fd[1] = -1;
			}
			if (current->fd[0] != -1)
			{
				close(current->fd[0]);
				current->fd[0] = -1;
			}
		}
		current = current->next;
	}
}
