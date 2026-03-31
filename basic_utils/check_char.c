/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toloandr <toloandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 22:16:46 by toloandr          #+#    #+#             */
/*   Updated: 2025/07/21 19:11:33 by toloandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_space(char c)
{
	if ((c >= 7 && c <= 13) || (c == ' '))
		return (1);
	return (0);
}

int	is_alpha(int c)
{
	if ((c >= 'A' && c <= 'Z') \
	|| (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}

int	is_alnum(int c)
{
	if (is_alpha(c) \
		|| (c >= '0' && c <= '9'))
		return (1);
	return (0);
}
