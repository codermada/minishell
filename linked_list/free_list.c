/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toloandr <toloandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 09:53:47 by toloandr          #+#    #+#             */
/*   Updated: 2025/07/17 21:18:57 by toloandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	free_list(t_list **list, int free_data)
{
	t_list	*current;

	while (*list)
	{
		current = (*list)->next;
		if (free_data)
		{
			if (current)
				free(current->data);
		}
		free(*list);
		*list = current;
	}
}
