/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toloandr <toloandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 13:24:47 by toloandr          #+#    #+#             */
/*   Updated: 2025/07/28 18:02:53 by toloandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

static void	append_char(char *str, char c, int i, int *j)
{
	if (str[i] == c)
	{
		str[*j] = str[i];
		(*j)++;
	}
}

static int	contains_quotes(char *str)
{
	while (*str)
	{
		if (*str == '\'' || *str == '\"')
			return (1);
		str++;
	}
	return (0);
}

static void	remove_quotes_(char *str)
{
	int	d[4];

	d[0] = 0;
	d[1] = 0;
	d[2] = 0;
	d[3] = 0;
	if (!str)
		return ;
	while (str[d[0]])
	{
		if (str[d[0]] == '"' && !d[3])
			d[2] = !d[2];
		if (str[d[0]] == '\'' && !d[2])
			d[3] = !d[3];
		if (d[2])
			append_char(str, '\'', d[0], &d[1]);
		if (d[3])
			append_char(str, '"', d[0], &d[1]);
		if ((str[d[0]] != '"') && (str[d[0]] != '\''))
			str[d[1]++] = str[d[0]];
		d[0]++;
	}
	str[d[1]] = '\0';
}

static void	update_hd_delim_quoted(t_list *tokens)
{
	t_list	*current;

	current = tokens;
	while (current)
	{
		if (((t_token *)current->data)->type == HEREDOC)
		{
			current->hd_delim_quoted = \
contains_quotes(((t_token *)current->next->data)->token);
		}
		current = current->next;
	}
}

void	remove_quotes(t_list *tokens)
{
	t_list	*current;

	current = tokens;
	update_hd_delim_quoted(tokens);
	while (current)
	{
		if (((t_token *)(current->data))->type == DQ)
			remove_quotes_\
(((t_token *)(current->data))->token);
		else if (((t_token *)(current->data))->type == SQ)
			remove_quotes_\
(((t_token *)(current->data))->token);
		current = current->next;
	}
}
