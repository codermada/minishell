/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_dup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toloandr <toloandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 19:52:42 by toloandr          #+#    #+#             */
/*   Updated: 2025/08/05 02:12:06 by toloandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "basic_utils.h"

char	*str_dup(char *str)
{
	int		i;
	char	*res;

	if (!str)
		return (NULL);
	res = malloc(sizeof(char) * (str_len(str) + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (*str)
		res[i++] = (*str++);
	res[i] = '\0';
	return (res);
}
