/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_cmds_utils_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toloandr <toloandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 23:06:26 by toloandr          #+#    #+#             */
/*   Updated: 2025/07/30 21:59:52 by toloandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

void	skip_to_next_chunk(t_list **current)
{
	while (*current)
	{
		if ((*current)->next_ == NULL)
		{
			*current = (*current)->next;
			break ;
		}
		*current = (*current)->next;
	}
	if (*current)
		*current = (*current)->next;
}

int	run_out_fork(t_list *tokens)
{
	char	**av;

	signal(SIGINT, SIG_IGN);
	if (tokens->tail->chunk_id == 0)
	{
		av = build_cmd(tokens);
		if (av)
		{
			if (is_built_in(av[0]) > 0)
			{
				run_built_in_sup(av, tokens);
				free(av);
				return (0);
			}
			if (av)
				free(av);
		}
	}
	return (1);
}

void	run_in_fork(t_ints i, t_list *current, char ***av)
{
	t_list	*tokens;
	int		redir;
	int		e;

	tokens = current->head;
	close_unused_pipes(tokens, i.fd_head_0, i.fd_tail_1);
	setup_stdio(i.fd_head_0, i.fd_tail_1, i.fd_head_1, i.fd_tail_0);
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	redir = run_redirs(current);
	if (redir == 1)
	{
		if (run_built_in(*av, current, 0) < 0)
		{
			run_cmd(*av, current);
			exit (0);
		}
	}
	e = exit_sub(tokens->exit);
	clean_in_fork(&tokens);
	exit (e);
}

void	assign_fds(t_list *current, t_ints *i)
{
	i->fd_head_0 = get_fd_head_0(current);
	i->fd_tail_1 = get_fd_tail_1(current);
	i->fd_head_1 = get_fd_head_1(current);
	i->fd_tail_0 = get_fd_tail_0(current);
}

void	close_fds(t_ints i)
{
	if (i.fd_head_0 != -1)
		close(i.fd_head_0);
	if (i.fd_tail_1 != -1)
		close(i.fd_tail_1);
}
