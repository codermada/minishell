/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toloandr <toloandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 08:50:14 by toloandr          #+#    #+#             */
/*   Updated: 2025/06/29 10:11:58 by toloandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# include <stdlib.h>
# include "dictionary.h"

typedef struct s_list
{
	int				id;
	int				chunk_id;
	int				fd[2];
	int				history_fd;
	int				hd_delim_quoted;
	char			*input;
	char			**av;
	char			**env;
	t_dict			**env_dict;
	int				exit;
	pid_t			pid;
	void			*data;
	struct s_list	*tail;
	struct s_list	*head;
	struct s_list	*prev;
	struct s_list	*next;
	struct s_list	*next_;
}	t_list;

int		list_append(t_list **list, void *data);
t_list	*remove_tail(t_list **list, int use_return, \
int free_data);
t_list	*remove_head(t_list **list, int use_return, \
int free_data);
void	free_list(t_list **list, int free_data);

#endif
