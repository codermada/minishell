/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_ins.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toloandr <toloandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 19:36:22 by toloandr          #+#    #+#             */
/*   Updated: 2025/08/05 14:12:18 by toloandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILT_INS_H
# define BUILT_INS_H

# include "parser.h"

int		get_arg_count(char **av);
void	echo(char **av, t_list *tokens);
int		cd(char **av, t_list *tokens);
void	pwd(char **av, t_list *tokens);
void	env(char **av, t_list *tokens);
void	unset(char **av, t_dict **env, t_list *tokens);
void	print_env(t_dict *env_dict);
int		check_key(char *key, int *i, \
t_list *tokens, char **dup_av_i);
int		check_av_i(char *av_i, int *i, \
t_list *tokens, char **dup_av_i);
int		is_valid_env_key(char *str);
int		export(char **av, t_dict **env_dict, t_list *tokens);
void	print_invalid_identifier_error(int *i, t_list *tokens);
void	exit_(char **av, t_list *tokens, int log);

#endif
