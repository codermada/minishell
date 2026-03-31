/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_env_item.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toloandr <toloandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 12:18:47 by toloandr          #+#    #+#             */
/*   Updated: 2025/07/17 20:11:57 by toloandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dictionary.h"

t_dict	*split_env_item(char *env_item)
{
	int		d[2];
	t_dict	*res;
	char	*tmp;

	res = malloc(sizeof(t_dict));
	res->key = malloc(sizeof(char) * (str_len_till_end(env_item, '=') + 1));
	res->value = malloc(sizeof(char) * (str_len_from_start(env_item, '=') + 1));
	res->next = NULL;
	if (!res || !res->key || !res->value)
		return (NULL);
	d[0] = 0;
	d[1] = 0;
	tmp = (char *)res->key;
	while (env_item[d[1]] != '=')
		tmp[d[0]++] = env_item[d[1]++];
	tmp[d[0]++] = '\0';
	d[1]++;
	d[0] = 0;
	tmp = (char *)res->value;
	while (env_item[d[1]])
		tmp[d[0]++] = env_item[d[1]++];
	tmp[d[0]++] = '\0';
	return (res);
}
