/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_append.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toloandr <toloandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 08:53:36 by toloandr          #+#    #+#             */
/*   Updated: 2025/08/02 22:21:09 by toloandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

static int	new_list(t_list **list, int id, void *data)
{
	*list = malloc(sizeof(t_list));
	if (!(*list))
		return (0);
	(*list)->id = id;
	(*list)->chunk_id = -1;
	(*list)->av = NULL;
	(*list)->input = NULL;
	(*list)->fd[0] = -1;
	(*list)->fd[1] = -1;
	(*list)->history_fd = -1;
	(*list)->hd_delim_quoted = -1;
	(*list)->env = NULL;
	(*list)->env_dict = NULL;
	(*list)->exit = -100;
	(*list)->pid = -1;
	(*list)->data = data;
	(*list)->tail = *list;
	(*list)->head = *list;
	(*list)->prev = NULL;
	(*list)->next = NULL;
	(*list)->next_ = NULL;
	return (1);
}

int	list_append(t_list **list, void *data)
{
	t_list	*last;
	t_list	*new;

	if (*list == NULL)
	{
		if (!new_list(list, 0, data))
			return (0);
	}
	else
	{
		last = *list;
		while (last->next)
			last = last->next;
		if (!new_list(&new, last->id + 1, data))
			return (0);
		(*list)->tail = new;
		new->head = *list;
		new->prev = last;
		last->next = new;
		last->next_ = new;
	}
	return (1);
}
