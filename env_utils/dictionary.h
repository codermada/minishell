/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionary.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toloandr <toloandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 16:14:33 by toloandr          #+#    #+#             */
/*   Updated: 2025/08/06 15:33:59 by toloandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DICTIONARY_H
# define DICTIONARY_H

# include <stdlib.h>
# include "basic_utils.h"

typedef struct s_dict
{
	int				id;
	int				initial_len;
	int				exported;
	int				assigned;
	void			*key;
	void			*value;
	void			*data;
	struct s_dict	*prev;
	struct s_dict	*next;
	struct s_dict	*last;
}	t_dict;

typedef struct s_data
{
	int	key_len;
	int	value_len;
}	t_data;

int		dict_add(t_dict **dict, void *key, \
void *value, int cmp(void *, void *));
int		dict_add_(t_dict **dict, void *key, \
void *value);
t_dict	*get_item(t_dict *dict, void *key, \
int cmp(void *, void *));
void	free_dict(t_dict **dict, int free_key, int free_value);

int		cmp(void *ptr_1, void *ptr_2);
int		str_len(char *str);
void	sort_env(char **env);
int		str_len_till_end(char *str, char end);
int		str_len_from_start(char *str, char start);
char	*build_env_item(char *key, char *value);
t_dict	*split_env_item(char *env_item);
t_dict	*system_env_to_dict(char **env);
char	**create_env(t_dict *env_dict);
void	free_env(char **env);

void	copy_dict(t_dict *head, t_dict **cpy);
void	sort_dict(t_dict **head);

#endif
