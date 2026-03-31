/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_dup_delim.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnomenja <nnomenja@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 13:14:35 by toloandr          #+#    #+#             */
/*   Updated: 2025/08/08 11:30:55 by nnomenja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "basic_utils.h"

static char	*str_n_dup(char *str, int n)
{
	int		i;
	char	*res;

	res = malloc(sizeof(char) * (n + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (i < n && str[i])
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*str_dup_delim(char *token)
{
	int	i;

	i = 0;
	if (token[i] && (token[i] > '0' && token[i] <= '9'))
		return (str_n_dup(token, 1));
	while (token[i] && (is_alnum(token[i]) \
	|| token[i] == '_'))
		i++;
	return (str_n_dup(token, i));
}
