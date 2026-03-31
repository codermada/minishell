/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toloandr <toloandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 16:55:23 by toloandr          #+#    #+#             */
/*   Updated: 2025/08/05 01:42:55 by toloandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_ins.h"

void	unset(char **av, t_dict **env, t_list *tokens)
{
	int		i;
	t_dict	*item;

	i = 1;
	if (av[i] != NULL)
	{
		if (av[i][0] == '-' && !is_space(av[i][1]))
		{
			print_error("minishell: options not supported");
			tokens->exit = -2;
			return ;
		}
	}
	while (av[i])
	{
		item = get_item(*env, av[i], cmp);
		if (!item)
			return ;
		((char *)item->key)[0] = '\0';
		((char *)item->value)[0] = '\0';
		i++;
	}
}
