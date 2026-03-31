/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toloandr <toloandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 07:44:08 by toloandr          #+#    #+#             */
/*   Updated: 2025/08/06 16:04:56 by toloandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

static int	check_next(int type, int type_next)
{
	if (type > 0)
		if (type_next >= 0)
			return (print_error("Invalid \
syntax (successive operators)"), 0);
	if (type == 0)
		if (type_next == 0)
			return (print_error("Invalid \
syntax (successive pipes)"), 0);
	return (1);
}

int	check_tokens(t_list *tokens)
{
	t_list	*current;

	current = tokens;
	if (current)
	{
		if (((t_token *)current->data)->type == 0)
			return (print_error("Invalid syntax (pipe at beginning)"), 0);
	}
	while (current)
	{
		if (((t_token *)current->data)->type >= 0)
		{
			if (current->next == NULL)
				return (print_error("Invalid syntax (operator at ending)"), 0);
		}
		if (current->next)
		{
			if (!check_next(((t_token *)current->data)->type, \
			((t_token *)current->next->data)->type))
				return (0);
		}
		current = current->next;
	}
	return (1);
}
