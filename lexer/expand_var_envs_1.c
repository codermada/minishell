/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_var_envs_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toloandr <toloandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 20:21:43 by toloandr          #+#    #+#             */
/*   Updated: 2025/08/04 20:47:24 by toloandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

char	*expand_(char *token, t_dict *env)
{
	char	*res;
	char	*expanded;

	res = NULL;
	while (*token)
	{
		if (should_expand(*token, *(token + 1), 1))
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
