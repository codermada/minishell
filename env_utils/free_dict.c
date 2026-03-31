/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_dict.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toloandr <toloandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 18:49:17 by toloandr          #+#    #+#             */
/*   Updated: 2025/07/15 18:43:05 by toloandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dictionary.h"

void	free_dict(t_dict **dict, int free_key, int free_value)
{
	t_dict	*tmp;

	if (!dict || !*dict)
		return ;
	while (*dict)
	{
		tmp = (*dict)->next;
		if (free_key && (*dict)->key)
			free((*dict)->key);
		if (free_value && (*dict)->value)
			free((*dict)->value);
		free((*dict)->data);
		free(*dict);
		*dict = tmp;
	}
}
