/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spacing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toloandr <toloandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 06:07:26 by toloandr          #+#    #+#             */
/*   Updated: 2025/07/18 14:29:33 by toloandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process_input.h"

static void	check_quotes(char *input, int i, int *d_quote, int *s_quote)
{
	if ((input[i] == '\'') && !(*d_quote))
		*s_quote = !(*s_quote);
	else if ((input[i] == '\"') && !(*s_quote))
		*d_quote = !(*d_quote);
}

char	*new_input(char *input, int exit_status)
{
	int		i;
	char	*res;
	int		d_quote;
	int		s_quote;

	res = NULL;
	i = 0;
	d_quote = 0;
	s_quote = 0;
	if (input == NULL)
		return (NULL);
	while (input[i])
	{
		check_quotes(input, i, &d_quote, &s_quote);
		if (!d_quote && !s_quote)
		{
			if (process_operators(&res, input, &i, exit_status))
				continue ;
		}
		if (!s_quote)
			process_exit_status(&res, input, &i, exit_status);
		res = str_n_join(res, &input[i], 1);
		i++;
	}
	return (free(input), res);
}
