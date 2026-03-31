/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   system_env_to_dict.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toloandr <toloandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 12:46:48 by toloandr          #+#    #+#             */
/*   Updated: 2025/08/05 12:17:13 by toloandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dictionary.h"

t_dict	*system_env_to_dict(char **env)
{
	int		i;
	t_dict	*res;
	t_dict	*tmp;

	if (!env)
		return (NULL);
	res = NULL;
	i = 0;
	while (env[i])
	{
		tmp = split_env_item(env[i]);
		if (tmp)
		{
			dict_add(&res, tmp->key, tmp->value, cmp);
			free(tmp);
		}
		i++;
	}
	res->initial_len = i;
	return (res);
}
