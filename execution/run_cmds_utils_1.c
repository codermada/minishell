/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_cmds_utils_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toloandr <toloandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 22:41:28 by toloandr          #+#    #+#             */
/*   Updated: 2025/07/30 21:58:05 by toloandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

int	get_fd_tail_1(t_list *chunk)
{
	t_list	*current;

	current = chunk;
	while (current)
	{
		if (current->next)
		{
			if (((t_token *)current->next->data)->type == PIPE)
			{
				return (current->next->fd[1]);
			}
		}
		current = current->next_;
	}
	return (-1);
}

int	get_fd_tail_0(t_list *chunk)
{
	t_list	*current;

	current = chunk;
	while (current)
	{
		if (current->next)
		{
			if (((t_token *)current->next->data)->type == PIPE)
			{
				return (current->next->fd[0]);
			}
		}
		current = current->next_;
	}
	return (-1);
}

int	get_fd_head_0(t_list *chunk)
{
	if (chunk->prev)
		return (chunk->prev->fd[0]);
	return (-1);
}

int	get_fd_head_1(t_list *chunk)
{
	if (chunk->prev)
		return (chunk->prev->fd[1]);
	return (-1);
}

void	setup_stdio(int fd_head_0, int fd_tail_1, \
	int fd_head_1, int fd_tail_0)
{
	if (fd_head_0 != -1)
	{
		close(fd_head_1);
		dup2(fd_head_0, STDIN_FILENO);
		close(fd_head_0);
	}
	if (fd_tail_1 != -1)
	{
		close(fd_tail_0);
		dup2(fd_tail_1, STDOUT_FILENO);
		close(fd_tail_1);
	}
}
