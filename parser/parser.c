/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toloandr <toloandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 17:11:33 by toloandr          #+#    #+#             */
/*   Updated: 2025/07/23 22:17:57 by toloandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	split_tokens(t_list *tokens)
{
	int		chunk_id;
	t_list	*current;
	int		*type;

	current = tokens;
	chunk_id = 0;
	while (current)
	{
		current->chunk_id = chunk_id;
		type = &((t_token *)current->data)->type;
		if (*type == PIPE)
		{
			if (pipe(current->fd) == -1)
			{
				print_error("pipe error");
				return ;
			}
			if (current->prev)
			{
				current->prev->next_ = NULL;
				chunk_id++;
			}
		}
		current = current->next;
	}
}
