/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toloandr <toloandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 19:38:07 by toloandr          #+#    #+#             */
/*   Updated: 2025/08/08 20:54:36 by toloandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_ins.h"

static int	check_option(char *av_1)
{
	if (!av_1)
		return (-1);
	if (av_1[0] == '-')
		av_1++;
	else
		return (0);
	if (av_1[0] != 'n')
		return (0);
	while (*av_1)
	{
		if (*av_1 != 'n' && !is_space(*av_1))
			return (0);
		av_1++;
	}
	return (1);
}

static void	check_options(int *i, int *nl, char **av)
{
	while (av[*i])
	{
		if (check_option(av[*i]) == 1)
		{
			(*nl)++;
			(*i)++;
		}
		else
			break ;
	}
}

void	echo(char **av, t_list *tokens)
{
	int	i;
	int	nl;

	(void)tokens;
	if (!av)
		return ;
	i = 1;
	nl = 0;
	check_options(&i, &nl, av);
	while (av[i])
	{
		put_str_colored(STDOUT_FILENO, av[i], COLOR_03BAFC);
		if (av[i + 1] != NULL)
			write(STDOUT_FILENO, " ", 1);
		i++;
	}
	if (nl == 0)
		write(STDOUT_FILENO, "\n", 1);
}
