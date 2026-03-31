/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_cmds_utils_3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toloandr <toloandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 23:48:22 by toloandr          #+#    #+#             */
/*   Updated: 2025/08/02 22:37:41 by toloandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

void	close_unused_pipes(t_list *tokens, int head_0, int tail_1)
{
	int		*type;
	t_list	*current;

	current = tokens;
	while (current)
	{
		type = &((t_token *)current->data)->type;
		if (*type == PIPE)
		{
			if (current->fd[0] != head_0)
				close(current->fd[0]);
			if (current->fd[1] != tail_1)
				close(current->fd[1]);
		}
		current = current->next;
	}
}

void	clean_in_fork(t_list **tokens)
{
	close((*tokens)->history_fd);
	close_fd_0_1(*tokens);
	free_dict((*tokens)->env_dict, 1, 1);
	free_env((*tokens)->env);
	free((*tokens)->input);
	free((*tokens)->av);
	free_tokens(tokens);
}

int	exit_sub(int tokens_exit)
{
	if (tokens_exit == -1)
		return (1);
	else if (tokens_exit > 0)
		return (tokens_exit);
	else
		return (0);
}
