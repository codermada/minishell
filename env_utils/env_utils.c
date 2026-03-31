/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toloandr <toloandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 10:05:25 by toloandr          #+#    #+#             */
/*   Updated: 2025/07/17 20:13:49 by toloandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	str_len_till_end(char *str, char end)
{
	int	len;

	len = 0;
	if (!str)
		return (len);
	while (*str && (*str != end))
	{
		len++;
		str++;
	}
	return (len);
}

int	str_len_from_start(char *str, char start)
{
	int	len;

	len = 0;
	if (!str)
		return (len);
	while (*str && (*str != start))
		str++;
	while (*str)
	{
		len++;
		str++;
	}
	return (len);
}
