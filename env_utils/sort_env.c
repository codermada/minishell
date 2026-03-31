/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toloandr <toloandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 14:07:35 by toloandr          #+#    #+#             */
/*   Updated: 2025/07/26 14:41:56 by toloandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "basic_utils.h"

static void	swap(char **a, char **b)
{
	char	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	sort_env(char **env)
{
	int	i;
	int	j;

	if (!env)
		return ;
	i = 0;
	while (env[i] != NULL)
	{
		j = 0;
		while (env[j + 1] != NULL)
		{
			if (str_cmp_(env[j], env[j + 1]) > 0)
				swap(&env[j], &env[j + 1]);
			j++;
		}
		i++;
	}
}
