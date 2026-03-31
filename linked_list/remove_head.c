/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delist.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toloandr <toloandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 09:09:51 by toloandr          #+#    #+#             */
/*   Updated: 2025/06/29 11:03:22 by toloandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_list	*remove_head(t_list **list, int use_return, int free_data)
{
	t_list	*old_head;
	t_list	*new_head;

	old_head = *list;
	new_head = NULL;
	if (*list)
		new_head = (*list)->next;
	*list = new_head;
	if (old_head)
		old_head->next = NULL;
	if (use_return)
		return (old_head);
	else
	{
		free_list(&old_head, free_data);
		return (NULL);
	}
}
