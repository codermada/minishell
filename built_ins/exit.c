/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toloandr <toloandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 06:53:48 by toloandr          #+#    #+#             */
/*   Updated: 2025/08/01 14:58:35 by toloandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_ins.h"
#include "process_input.h"

static int	is_number(char *av_)
{
	int	i;

	if (!av_ || !av_[0])
		return (0);
	i = 0;
	if (av_[0] == '-' || av_[0] == '+')
		i++;
	if (!av_[i])
		return (0);
	while (av_[i])
	{
		if (av_[i] < '0' || av_[i] > '9')
			return (0);
		i++;
	}
	if (((str_cmp_(av_, "9223372036854775807") > 0) \
	&& (str_len(av_) >= 20)) \
	|| ((str_cmp_(av_, "-9223372036854775808") > 0) \
	&& (str_len(av_) >= 21)) \
	|| ((str_cmp_(av_, "+9223372036854775807") > 0) \
	&& (str_len(av_) >= 21)))
		return (0);
	return (1);
}

static void	print_not_numeric_error(char *av_2)
{
	put_str_fd(STDERR_FILENO, "minishell: exit: ");
	put_str_fd(STDERR_FILENO, av_2);
	print_error(" : numeric argument required");
}

static void	print_exit_(char *color, int log)
{
	if (log)
	{
		put_str_colored(STDOUT_FILENO, "exit", color);
		put_str_fd(STDOUT_FILENO, "\n");
	}
}

void	exit_(char **av, t_list *tokens, int log)
{
	if (av[1] == NULL)
	{
		print_exit_(G, log);
		tokens->exit = 0;
	}
	else if (av[2] != NULL)
	{
		print_exit_(Y, log);
		print_error("exit: too many arguments");
		tokens->exit = -1;
	}
	else if (!is_number(av[1]))
	{
		print_not_numeric_error(av[1]);
		tokens->exit = 2;
	}
	else
	{
		print_exit_(G, log);
		tokens->exit = ft_atol(av[1]);
		if (tokens->exit < 0)
			tokens->exit = (unsigned char)tokens->exit;
	}
}
