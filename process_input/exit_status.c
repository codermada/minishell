/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_status.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toloandr <toloandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 11:26:07 by toloandr          #+#    #+#             */
/*   Updated: 2025/08/01 15:05:18 by toloandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process_input.h"

static unsigned int	convert(unsigned int n)
{
	return (n & 0xFF);
}

static int	len_number(unsigned int number)
{
	int	len;

	if (number == 0)
		return (1);
	len = 0;
	while (number)
	{
		len++;
		number /= 10;
	}
	return (len);
}

char	*i_to_a(unsigned long long n)
{
	int					i;
	unsigned long long	n_;
	char				*res;

	n_ = convert(n);
	i = len_number(n_);
	res = malloc(sizeof(char) * (i + 1));
	if (!res)
		return (NULL);
	res[i] = '\0';
	i--;
	while (i >= 0)
	{
		res[i] = '0' + (n_ % 10);
		i--;
		n_ /= 10;
	}
	return (res);
}
