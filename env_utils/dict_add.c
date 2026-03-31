/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toloandr <toloandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 16:19:33 by toloandr          #+#    #+#             */
/*   Updated: 2025/08/07 02:49:38 by toloandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dictionary.h"

static int	new_item(t_dict **dict_node, int id, void *key, void *value)
{
	*dict_node = malloc(sizeof(t_dict));
	if (*dict_node == NULL)
		return (0);
	(*dict_node)->id = id;
	(*dict_node)->initial_len = -1;
	(*dict_node)->exported = 0;
	(*dict_node)->assigned = 1;
	(*dict_node)->key = key;
	(*dict_node)->value = value;
	(*dict_node)->data = malloc(sizeof(t_data));
	if ((*dict_node)->data == NULL)
		return (free(*dict_node), 0);
	((t_data *)(*dict_node)->data)->key_len = str_len((char *)key);
	((t_data *)(*dict_node)->data)->value_len = str_len((char *)value);
	(*dict_node)->prev = NULL;
	(*dict_node)->next = NULL;
	(*dict_node)->last = *dict_node;
	return (1);
}

static void	link_nodes(t_dict *last, t_dict *new)
{
	last->next = new;
	new->prev = last;
}

int	dict_add(t_dict **dict, void *key, void *value, int cmp(void *, void *))
{
	t_dict	*last;
	t_dict	*new;

	if (*dict == NULL)
	{
		if (!new_item(dict, 0, key, value))
			return (0);
	}
	else
	{
		last = *dict;
		while (last->next)
		{
			if (cmp(last->key, key) == 0)
				return (-1);
			last = last->next;
		}
		if (cmp(last->key, key) == 0)
			return (-1);
		if (!new_item(&new, last->id + 1, key, value))
			return (0);
		link_nodes(last, new);
		(*dict)->last = new;
	}
	return (1);
}

int	dict_add_(t_dict **dict, void *key, \
void *value)
{
	t_dict	*last;
	t_dict	*new;

	if (*dict == NULL)
	{
		if (!new_item(dict, 0, key, value))
			return (0);
	}
	else
	{
		last = *dict;
		while (last->next)
		{
			last = last->next;
		}
		if (!new_item(&new, last->id + 1, key, value))
			return (0);
		link_nodes(last, new);
		(*dict)->last = new;
	}
	return (1);
}
