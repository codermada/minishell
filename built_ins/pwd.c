/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toloandr <toloandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 15:49:15 by toloandr          #+#    #+#             */
/*   Updated: 2025/07/26 23:36:11 by toloandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_ins.h"

void	pwd(char **av, t_list *tokens)
{
	char	res[1000];

	res[0] = '\0';
	if (av[1] != NULL)
	{
		if (av[1][0] == '-' && !is_space(av[1][1]))
		{
			print_error("minishell: options not supported");
			tokens->exit = -2;
			return ;
		}
	}
	if (getcwd(res, 1000) == NULL)
	{
		print_error("minishell: pwd: cwd has been removed");
		tokens->exit = -2;
		return ;
	}
	put_str_colored(STDOUT_FILENO, res, COLOR_03BAFC);
	write(STDOUT_FILENO, "\n", 1);
}
