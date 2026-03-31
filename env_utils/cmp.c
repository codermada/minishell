/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toloandr <toloandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 12:52:41 by toloandr          #+#    #+#             */
/*   Updated: 2025/07/15 14:09:55 by toloandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dictionary.h"

int	cmp(void *ptr_1, void *ptr_2)
{
	unsigned char	*p1;
	unsigned char	*p2;

	p1 = (unsigned char *)ptr_1;
	p2 = (unsigned char *)ptr_2;
	if (!p1 || !p2)
		return (-1);
	while (*p1 && *p2)
	{
		if (*p1 != *p2)
			return (1);
		p1++;
		p2++;
	}
	if (*p1 != *p2)
		return (1);
	return (0);
}
