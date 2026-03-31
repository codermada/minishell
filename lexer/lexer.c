/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toloandr <toloandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 20:51:26 by toloandr          #+#    #+#             */
/*   Updated: 2025/08/05 13:20:20 by toloandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_list	*lexing(char *input)
{
	char	*input_dup;
	char	*token;
	t_list	*res;
	t_token	*tok;

	input_dup = str_dup(input);
	token = str_tok(input_dup, " \n\t");
	res = NULL;
	while (token)
	{
		tok = malloc(sizeof(t_token));
		if (!tok)
		{
			free_tokens(&res);
			free(input_dup);
			return (NULL);
		}
		tok->fd = -1;
		tok->type = is_operator(token);
		tok->token = str_dup(token);
		list_append(&res, tok);
		token = str_tok(NULL, " \n\t");
	}
	free(input_dup);
	return (res);
}

void	append_expanded(char *token, char **res, \
char **expanded, t_dict *env_dict)
{
	*expanded = expand(token, env_dict);
	*res = str_n_join(*res, *expanded, str_len(*expanded));
	*res = str_n_join(*res, " ", 1);
	free(*expanded);
}

char	*str_from_tokens(t_list *tokens, t_dict *env_dict)
{
	char	*res;
	char	*expanded;
	t_list	*current;

	res = NULL;
	current = tokens;
	while (current)
	{
		if (is_operator(((t_token *)current->data)->token) == HEREDOC)
		{
			if (current->next)
				((t_token *)current->next->data)->type = DELIM;
		}
		if (((t_token *)current->data)->type == DELIM)
		{
			res = str_n_join(res, ((t_token *)current->data)->token, \
			str_len(((t_token *)current->data)->token));
			res = str_n_join(res, " ", 1);
		}
		else
			append_expanded(((t_token *)current->data)->token, \
			&res, &expanded, env_dict);
		current = current->next;
	}
	return (res);
}

void	free_tokens(t_list **tokens)
{
	t_list	*current;

	while (*tokens)
	{
		current = (*tokens)->next;
		if ((*tokens)->data)
		{
			free(((t_token *)(*tokens)->data)->token);
			free((*tokens)->data);
		}
		free(*tokens);
		*tokens = current;
	}
}
