/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toloandr <toloandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 01:02:30 by toloandr          #+#    #+#             */
/*   Updated: 2025/08/08 20:55:52 by toloandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

int	is_path(const char *str)
{
	int	count;

	count = 0;
	if (str_cmp((char *)str, ".") \
	|| str_cmp((char *)str, ".."))
		return (1);
	while (*str)
	{
		if (*str == '/')
			count++;
		str++;
	}
	return (count);
}
