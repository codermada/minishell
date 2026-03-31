/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnomenja <nnomenja@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 16:46:54 by toloandr          #+#    #+#             */
/*   Updated: 2025/08/08 11:40:51 by nnomenja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "process_input.h"
#include "lexer.h"
#include "history.h"

static int	valid_input(char *input)
{
	if (*input == '\0')
		return (0);
	while (*input)
	{
		if (!is_space(*input))
			return (1);
		input++;
	}
	return (0);
}

static void	exit_minishell(int status, t_dict **env_cpy)
{
	rl_clear_history();
	free_dict(env_cpy, 1, 1);
	if (status >= 0)
		exit (status);
}

static int	init_minishell(int ac, char **av, \
char **env, t_dict **env_cpy)
{
	if (ac != 1)
		return (print_error("usage: ./minishell (no arguments)"), 0);
	(void)av;
	*env_cpy = system_env_to_dict(env);
	dict_add_(env_cpy, str_dup("0"), str_dup("minishell"));
	if (PRINT_WELCOME)
		print_welcome();
	return (1);
}

static void	add_history_eval(int *fd_history, t_exit *e, \
char **input, t_dict **env_cpy)
{
	add_history_(*input, fd_history);
	*input = new_input(*input, e->status);
	*e = eval(*input, env_cpy, *fd_history);
	free(*input);
}

int	main(int ac, char **av, char **env)
{
	t_m	m;

	init_history(&m.fd_history);
	if (!init_minishell(ac, av, env, &m.env_cpy))
		return (close(m.fd_history), 1);
	m.e = (t_exit){0, -1};
	while (1)
	{
		get_line(&m.input);
		if (get_status(-1) == 130)
			m.e = (t_exit){130, -1};
		if (!m.input)
			break ;
		if (!valid_input(m.input))
		{
			free(m.input);
			continue ;
		}
		add_history_eval(&m.fd_history, &m.e, &m.input, &m.env_cpy);
		if (m.e.exit_shell >= 0)
			break ;
	}
	close(m.fd_history);
	exit_minishell(m.e.status, &m.env_cpy);
}
