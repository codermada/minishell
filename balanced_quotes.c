/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   balanced_quotes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toloandr <toloandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 18:06:39 by toloandr          #+#    #+#             */
/*   Updated: 2025/07/18 12:30:32 by toloandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "basic_utils.h"

int	balanced_quotes(char *str)
{
	bool	in_single;
	bool	in_double;
	int		i;
	int		res;

	in_single = false;
	in_double = false;
	i = 0;
	if (!str)
		return (1);
	while (str[i])
	{
		if (str[i] == '\'' && !in_double)
			in_single = !in_single;
		else if (str[i] == '"' && !in_single)
			in_double = !in_double;
		i++;
	}
	res = !in_single && !in_double;
	if (res == false)
		print_error("Quotes unbalanced");
	return (res);
}
