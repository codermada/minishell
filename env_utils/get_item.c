/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_item.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toloandr <toloandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 18:37:47 by toloandr          #+#    #+#             */
/*   Updated: 2025/06/29 18:40:18 by toloandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dictionary.h"

t_dict	*get_item(t_dict *dict, void *key, int cmp(void *, void *))
{
	t_dict	*current;

	current = dict;
	while (current)
	{
		if (cmp(current->key, key) == 0)
			return (current);
		current = current->next;
	}
	return (NULL);
}
