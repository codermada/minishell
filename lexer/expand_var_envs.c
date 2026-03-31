/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_var_envs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnomenja <nnomenja@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 13:06:26 by toloandr          #+#    #+#             */
/*   Updated: 2025/08/08 11:37:03 by nnomenja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

static void	update_quote_state(char c, int *d_quote, int *s_quote)
{
	if (c == '\"' && !(*s_quote))
		*d_quote = !(*d_quote);
	else if (c == '\'' && !(*d_quote))
		*s_quote = !(*s_quote);
}

char	*expand_variable(char **token_ptr, t_dict *env)
{
	char	*var;
	t_dict	*item;
	char	*res;

	res = NULL;
	(*token_ptr)++;
	var = str_dup_delim(*token_ptr);
	item = get_item(env, var, cmp);
	*token_ptr += str_len(var);
	if (item && item->value)
		res = str_n_join(NULL, item->value, ((t_data *)item->data)->value_len);
	free(var);
	return (res);
}

int	should_expand(char c, char c_, int cond)
{
	if ((((c == '$') && ((c_ != '\'') && (c_ != '"')) \
		&& (!is_space(c_)) \
		&& (c_ != '\0'))) && cond)
		return (1);
	return (0);
}

char	*expand(char *token, t_dict *env)
{
	int		d_quote;
	int		s_quote;
	char	*res;
	char	*expanded;

	d_quote = 0;
	s_quote = 0;
	res = NULL;
	while (*token)
	{
		update_quote_state(*token, &d_quote, &s_quote);
		if (should_expand(*token, *(token + 1), !s_quote))
		{
			expanded = expand_variable(&token, env);
			if (expanded)
			{
				res = str_n_join(res, expanded, str_len(expanded));
				free(expanded);
			}
			continue ;
		}
		res = str_n_join(res, token++, 1);
	}
	return (res);
}
