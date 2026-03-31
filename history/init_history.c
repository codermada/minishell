/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_history.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toloandr <toloandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 20:05:40 by nnomenja          #+#    #+#             */
/*   Updated: 2025/08/02 22:52:50 by toloandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "history.h"

static char	*read_history_(int *fd)
{
	char	*buff;
	int		len;
	char	*res;

	res = NULL;
	while (1)
	{
		buff = malloc(sizeof(char) * 2);
		if (!buff)
			return (NULL);
		len = read(*fd, buff, 1);
		buff[1] = 0;
		if (!len)
		{
			free (buff);
			break ;
		}
		res = str_n_join(res, buff, 1);
		free (buff);
	}
	return (res);
}

static void	synchronize_history(char **data)
{
	if (!data)
		return ;
	while (*data)
	{
		add_history(*data);
		data++;
	}
}

static void	clean_data(char **data)
{
	int		i;

	i = -1;
	while (data[++i])
	{
		free(data[i]);
	}
	free(data);
}

void	add_history_(char *s, int *fd)
{
	add_history(s);
	if (*fd < 0)
		return ;
	put_str_fd(*fd, s);
	write(*fd, "\n", 1);
}

void	init_history(int *fd)
{
	char	**data;
	char	*s;

	*fd = open("minishell_history", O_CREAT | O_RDWR | O_APPEND, 0644);
	if (*fd == -1)
		return ;
	s = read_history_(fd);
	if (!s)
		return ;
	data = ft_split(s, '\n');
	synchronize_history(data);
	clean_data(data);
	free(s);
}
