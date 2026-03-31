/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnomenja <nnomenja@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 16:46:05 by toloandr          #+#    #+#             */
/*   Updated: 2025/08/08 11:09:05 by nnomenja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <readline/readline.h>
# include <readline/history.h>
# include <stdio.h>
# include <stdlib.h>
# include <signal.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>

# include "dictionary.h"
# include "list.h"

# define PRINT_WELCOME	1

typedef struct s_exit
{
	long long	status;
	long long	exit_shell;
}	t_exit;

typedef struct s_m
{
	char	*input;
	t_exit	e;
	t_dict	*env_cpy;
	int		fd_history;
}	t_m;

t_list	*get_list(t_list *list);
int		get_status(int status);
t_exit	exit_status(int exit, int status);
void	process_tokens(t_list **tokens, t_dict **env_dict);

void	get_line(char **input);
void	clean_up(t_list **tokens);
int		balanced_quotes(char *str);

t_exit	eval(char *input, t_dict **env, int fd_history);

#endif
