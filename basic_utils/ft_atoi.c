/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toloandr <toloandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 20:49:32 by toloandr          #+#    #+#             */
/*   Updated: 2025/03/10 10:39:26 by toloandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

static int	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

static int	is_neg(const char *nptr)
{
	char	*tmp;

	tmp = (char *)nptr;
	while ((*tmp >= 9 && *tmp <= 13) || *tmp == ' ')
		tmp++;
	if (*tmp == '-')
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int	neg;
	int	signs;
	int	res;

	res = 0;
	neg = is_neg(nptr);
	signs = 0;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == ' ')
		nptr++;
	while (*nptr == '-' || *nptr == '+')
	{
		nptr++;
		signs++;
	}
	while (ft_isdigit(*nptr))
	{
		res = res * 10 + (*nptr - '0');
		nptr++;
	}
	if (neg % 2 != 0)
		res = -res;
	if (signs >= 2)
		return (0);
	return (res);
}
