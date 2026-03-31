/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toloandr <toloandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 12:53:53 by toloandr          #+#    #+#             */
/*   Updated: 2025/08/02 22:37:28 by toloandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

int	run_built_in(char **av, t_list *chunk, int log)
{
	if (is_built_in(av[0]) == BUILT_IN_ECHO)
		return (echo(av, chunk->head), BUILT_IN_ECHO);
	if (is_built_in(av[0]) == BUILT_IN_CD)
	{
		if (cd(av, chunk->head) == 1)
			return (BUILT_IN_CD);
		return (-1);
	}
	if (is_built_in(av[0]) == BUILT_IN_PWD)
		return (pwd(av, chunk->head), BUILT_IN_PWD);
	if (is_built_in(av[0]) == BUILT_IN_ENV)
		return (env(av, chunk->head), BUILT_IN_ENV);
	if (is_built_in(av[0]) == BUILT_IN_UNSET)
		return (unset(av, chunk->head->env_dict, chunk->head), BUILT_IN_UNSET);
	if (is_built_in(av[0]) == BUILT_IN_EXPORT)
		return (export(av, chunk->head->env_dict, chunk->head), \
		BUILT_IN_EXPORT);
	if (is_built_in(av[0]) == BUILT_IN_EXIT)
		return (exit_(av, chunk->head, log), BUILT_IN_EXIT);
	return (-1);
}

int	run_built_in_sup(char **av, t_list *chunk)
{
	int	fd_stdin;
	int	fd_stdout;
	int	res;

	res = -1;
	fd_stdin = dup(STDIN_FILENO);
	fd_stdout = dup(STDOUT_FILENO);
	if (run_redirs(chunk) == 1)
		res = run_built_in(av, chunk, 1);
	dup2(fd_stdin, STDIN_FILENO);
	dup2(fd_stdout, STDOUT_FILENO);
	close(fd_stdin);
	close(fd_stdout);
	return (res);
}

static void	print_exit(int status, char *err, char *other, t_list *chunk)
{
	t_list	*tokens;

	tokens = chunk->head;
	if (err[0] != '\0')
	{
		put_str_fd(STDERR_FILENO, "minishell: ");
		put_str_fd(STDERR_FILENO, other);
		put_str_fd(STDERR_FILENO, ":");
		print_error(err);
	}
	close(tokens->history_fd);
	close_fd_0_1(tokens);
	free_dict(tokens->env_dict, 1, 1);
	free_env(tokens->env);
	free(tokens->av);
	free(tokens->input);
	free_tokens(&tokens);
	exit (status);
}

int	count_args(t_list *chunk)
{
	int		ac;
	t_list	*current;
	int		*type;

	ac = 0;
	current = chunk;
	while (current)
	{
		type = &((t_token *)current->data)->type;
		if (*type == ARG)
		{
			if (str_len(((t_token *)current->data)->token) > 0)
				ac++;
		}
		current = current->next_;
	}
	return (ac);
}

void	run_cmd(char **av, t_list *chunk)
{
	char	*path_cmd;
	int		e;

	if (av[0] == NULL && count_args(chunk) == 0)
		print_exit(0, "", "", chunk);
	e = is_executable(av[0], *(chunk->head->env_dict), &path_cmd);
	if (!path_cmd)
	{
		if (e == 126)
		{
			if (is_directory(av[0]) == 1)
				print_exit(126, " Is a directory", av[0], chunk);
			print_exit(126, " Permission denied", av[0], chunk);
		}
		if (!is_path(av[0]))
			print_exit(127, " command not found", av[0], chunk);
		if (is_directory(av[0]) == -1)
			print_exit(127, " No such file or directory", av[0], chunk);
	}
	if (is_directory(path_cmd) == 1)
		print_exit(126, " Is a directory", av[0], chunk);
	execve(path_cmd, av, chunk->head->env);
	free(path_cmd);
	print_exit(1, "execve error", NULL, chunk);
}
