/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tag_all.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toloandr <toloandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 06:50:07 by toloandr          #+#    #+#             */
/*   Updated: 2025/07/23 23:47:02 by toloandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

static void	tag_next(int type, int *type_next)
{
	if (type == INFILE)
		*type_next = IN_FILENAME;
	if (type == OUTFILE)
		*type_next = OUT_FILENAME;
	if (type == APPEND)
		*type_next = APPEND_FILENAME;
	if (type == HEREDOC)
		*type_next = DELIM;
}

static void	tag_remainders(t_list *tokens)
{
	t_list	*current;
	int		*type;

	current = tokens;
	while (current)
	{
		type = &((t_token *)current->data)->type;
		if ((*type == -1) \
		|| (*type == SQ) \
		|| (*type == DQ))
			*type = ARG;
		current = current->next;
	}
}

void	tag_all(t_list *tokens)
{
	t_list	*current;

	current = tokens;
	while (current)
	{
		if (current->next)
		{
			tag_next(((t_token *)current->data)->type, \
			&((t_token *)current->next->data)->type);
		}
		current = current->next;
	}
	tag_remainders(tokens);
}
