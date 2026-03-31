/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_history.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnomenja <nnomenja@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 20:11:13 by nnomenja          #+#    #+#             */
/*   Updated: 2025/08/01 20:35:28 by nnomenja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	count_word(char const *str, char c)
{
	int	wc;
	int	in_word;

	wc = 0;
	in_word = 0;
	while (*str)
	{
		if (*str == c)
			in_word = 0;
		else
		{
			if (in_word == 0)
			{
				in_word = 1;
				wc++;
			}
		}
		str++;
	}
	return (wc);
}

static int	word_len(char const *s, char c)
{
	int	len;

	len = 0;
	while (*s != c && *s)
	{
		len++;
		s++;
	}
	return (len);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		wc;
	int		wl;
	char	**res;

	i = 0;
	wc = count_word(s, c);
	res = malloc(sizeof(char *) * (wc + 1));
	if (!res)
		return (NULL);
	while (i < wc)
	{
		while (*s == c && *s)
			s++;
		wl = word_len(s, c);
		res[i] = malloc(sizeof(char) * (wl + 1));
		j = 0;
		while (j < wl)
			res[i][j++] = *s++;
		res[i][j] = '\0';
		i++;
	}
	res[i] = NULL;
	return (res);
}
