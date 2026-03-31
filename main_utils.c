/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnomenja <nnomenja@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 12:48:46 by toloandr          #+#    #+#             */
/*   Updated: 2025/08/07 09:17:25 by nnomenja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "process_input.h"
#include "lexer.h"

static void	handle_sigint(int sig)
{
	(void)sig;
	rl_replace_line("", 0);
	write(STDOUT_FILENO, "\n", 1);
	rl_on_new_line();
	rl_redisplay();
	get_status(130);
}

void	get_line(char **input)
{
	char	*prompt;

	prompt = "\001\x1b[34m\002minishell$ \001\x1b[0m\002";
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, handle_sigint);
	*input = readline(prompt);
}

int	get_status(int value)
{
	static int	s = 0;
	int			tmp;

	if (value == 130)
	{
		s = value;
		return (s);
	}
	if (value == -1)
	{
		tmp = s;
		s = 0;
		return (tmp);
	}
	return (0);
}
