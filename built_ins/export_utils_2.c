/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toloandr <toloandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 13:54:38 by toloandr          #+#    #+#             */
/*   Updated: 2025/08/05 14:11:57 by toloandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_ins.h"

int	check_key(char *key, int *i, t_list *tokens, char **dup_av_i)
{
	if (!is_valid_env_key(key))
	{
		print_invalid_identifier_error(i, tokens);
		free(*dup_av_i);
		return (0);
	}
	return (1);
}

int	check_av_i(char *av_i, int *i, t_list *tokens, char **dup_av_i)
{
	int	j;

	if (!av_i)
	{
		print_invalid_identifier_error(i, tokens);
		free(*dup_av_i);
		return (0);
	}
	j = 0;
	while (av_i[j])
	{
		if (!is_space(av_i[j]))
			break ;
		j++;
	}
	if (av_i[j] == '=')
	{
		print_invalid_identifier_error(i, tokens);
		free(*dup_av_i);
		return (0);
	}
	return (1);
}
