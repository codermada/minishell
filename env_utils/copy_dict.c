/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_dict.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toloandr <toloandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 13:40:13 by toloandr          #+#    #+#             */
/*   Updated: 2025/08/06 15:33:44 by toloandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dictionary.h"

void	copy_dict(t_dict *head, t_dict **cpy)
{
	t_dict	*current;
	t_dict	*item;

	current = head;
	*cpy = NULL;
	while (current)
	{
		dict_add_(cpy, str_dup((char *)current->key), \
		str_dup((char *)current->value));
		item = get_item(*cpy, (char *)current->key, cmp);
		item->id = current->id;
		item->initial_len = current->initial_len;
		item->exported = current->exported;
		item->assigned = current->assigned;
		current = current->next;
	}
}
