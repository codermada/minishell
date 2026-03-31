/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_cmds.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toloandr <toloandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 13:09:55 by toloandr          #+#    #+#             */
/*   Updated: 2025/07/30 21:50:18 by toloandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static int	wait_for_child_processes(int pid, int *status, t_list *tokens)
{
	t_list	*current;

	current = tokens;
	waitpid(pid, status, 0);
	while (current)
	{
		if (current->pid > 0 && current->pid != pid)
			waitpid(current->pid, NULL, 0);
		current = current->next;
	}
	if (WIFEXITED(*status))
		return (WEXITSTATUS(*status));
	else if (WIFSIGNALED(*status))
		return (128 + WTERMSIG(*status));
	return (1);
}

int	run_cmds(t_list *tokens)
{
	t_list	*current;
	char	**av;
	t_ints	i;
	pid_t	pid;

	current = tokens;
	if (!run_out_fork(tokens))
		return (0);
	while (current)
	{
		assign_fds(current, &i);
		av = build_cmd(current);
		tokens->av = av;
		current->pid = fork_1();
		pid = current->pid;
		if (current->pid == -1)
			return (free(av), 1);
		if (current->pid == 0)
			run_in_fork(i, current, &av);
		free(av);
		skip_to_next_chunk(&current);
		close_fds(i);
	}
	close_fd_pipes(tokens);
	return (wait_for_child_processes(pid, &i.status, tokens));
}
