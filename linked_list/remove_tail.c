/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_tail.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toloandr <toloandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 09:09:51 by toloandr          #+#    #+#             */
/*   Updated: 2025/07/13 17:50:29 by toloandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_list	*remove_tail(t_list **list, int use_return, int free_data)
{
	t_list	*new_tail;
	t_list	*last;

	last = *list;
	new_tail = NULL;
	while (last->next)
		last = last->next;
	if (last && last->prev)
		new_tail = last->prev;
	new_tail->next = NULL;
	if (use_return)
		return (last);
	else
	{
		free_list(&last, free_data);
		return (NULL);
	}
}
