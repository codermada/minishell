/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toloandr <toloandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 22:32:39 by toloandr          #+#    #+#             */
/*   Updated: 2025/07/23 13:08:07 by toloandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dictionary.h"

char	**create_env(t_dict *env_dict)
{
	int		i;
	int		env_count;
	char	**env;

	env_count = env_dict->last->id + 1;
	env = malloc(sizeof(char *) * (env_count + 1));
	if (!env)
		return (NULL);
	i = 0;
	while (i < env_count)
	{
		env[i] = build_env_item(env_dict->key, env_dict->value);
		env_dict = env_dict->next;
		i++;
	}
	env[i] = NULL;
	return (env);
}

void	free_env(char **env)
{
	int		i;

	i = 0;
	while (env[i])
	{
		free(env[i]);
		i++;
	}
	free(env[i]);
	free(env);
}
