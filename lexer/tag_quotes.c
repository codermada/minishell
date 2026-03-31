/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_manage_quotes.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toloandr <toloandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 02:48:35 by toloandr          #+#    #+#             */
/*   Updated: 2025/07/18 10:38:33 by toloandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

static int	first(char *token)
{
	if (token == NULL)
		return (-2);
	while (*token)
	{
		if (*token == '\'')
			return (SQ);
		else if (*token == '\"')
			return (DQ);
		token++;
	}
	return (-1);
}

void	tag_quotes(t_list *tokens)
{
	t_list	*current;
	int		qtype;

	current = tokens;
	while (current)
	{
		qtype = first(((t_token *)current->data)->token);
		if (qtype == SQ || qtype == DQ)
			((t_token *)current->data)->type = qtype;
		current = current->next;
	}
}
