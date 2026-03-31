/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_dict.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toloandr <toloandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 14:46:07 by toloandr          #+#    #+#             */
/*   Updated: 2025/08/06 15:02:05 by toloandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dictionary.h"

static void	copy_node(t_dict *dst, t_dict *src)
{
	dst->key = src->key;
	dst->value = src->value;
	dst->assigned = src->assigned;
	dst->exported = src->exported;
}

static void	swap(t_dict *node_1, t_dict *node_2)
{
	t_dict	tmp;

	copy_node(&tmp, node_1);
	copy_node(node_1, node_2);
	copy_node(node_2, &tmp);
}

void	sort_dict(t_dict **head)
{
	t_dict	*out;
	t_dict	*in;

	out = *head;
	while (out)
	{
		in = out->next;
		while (in)
		{
			if (str_cmp_(out->key, in->key) > 0)
				swap(in, out);
			in = in->next;
		}
		out = out->next;
	}
}
