/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toloandr <toloandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 15:38:02 by toloandr          #+#    #+#             */
/*   Updated: 2025/08/08 07:19:50 by toloandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_ins.h"

int	get_arg_count(char **av)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!av)
		return (0);
	while (av[i])
	{
		i++;
		count++;
	}
	return (count);
}

static int	get_home(char **av, t_list *tokens)
{
	t_dict	*item;
	char	buff[1000];

	if (get_arg_count(av) == 1)
	{
		if (getcwd(buff, 1000) == NULL)
			print_error("getcwd: cannot access parent \
directories: No such file or directory");
		item = get_item(*(tokens->env_dict), "HOME", cmp);
		if (!item)
		{
			print_error(" HOME not set");
			tokens->exit = -1;
			return (1);
		}
		if (chdir((char *)item->value) < 0)
		{
			perror("minishell: cd");
			tokens->exit = -1;
			return (0);
		}
		return (1);
	}
	return (2);
}

int	cd(char **av, t_list *tokens)
{
	char	buff[1000];

	if (get_home(av, tokens) == 1)
		return (0);
	if (get_arg_count(av) > 2)
	{
		print_error(" too many arguments");
		tokens->exit = -1;
		return (1);
	}
	if (getcwd(buff, 1000) == NULL)
	{
		print_error(" There is a problem with the current working directory");
		tokens->exit = -1;
		return (1);
	}
	if (chdir(av[1]) != 0)
	{
		perror("minishell: cd");
		tokens->exit = -1;
		return (1);
	}
	return (0);
}
