/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_env_item.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toloandr <toloandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 10:03:27 by toloandr          #+#    #+#             */
/*   Updated: 2025/07/15 12:20:55 by toloandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dictionary.h"

char	*build_env_item(char *key, char *value)
{
	int		i;
	int		k;
	char	*res;

	res = malloc(sizeof(char) * (str_len(key) + str_len(value) + 2));
	if (!res)
		return (NULL);
	i = 0;
	k = 0;
	if ((key == NULL) || (value == NULL))
		return (NULL);
	while (key[i])
		res[k++] = key[i++];
	res[k++] = '=';
	i = 0;
	while (value[i])
		res[k++] = value[i++];
	res[k++] = '\0';
	return (res);
}
