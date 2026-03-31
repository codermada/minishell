/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toloandr <toloandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 11:55:37 by toloandr          #+#    #+#             */
/*   Updated: 2025/07/30 21:57:51 by toloandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include "built_ins.h"
# include <fcntl.h>
# include <errno.h>

# define BUILT_IN_ECHO 401
# define BUILT_IN_CD 402
# define BUILT_IN_PWD 403
# define BUILT_IN_EXPORT 404
# define BUILT_IN_UNSET 405
# define BUILT_IN_ENV 406
# define BUILT_IN_EXIT 407

typedef struct s_ints
{
	int	status;
	int	fd_head_0;
	int	fd_head_1;
	int	fd_tail_0;
	int	fd_tail_1;
}	t_ints;

int		is_path(const char *str);
int		is_directory(char *path);
int		is_executable(char *cmd, t_dict *env_dict, char **path_cmd);
int		is_built_in(char *command);
char	**build_cmd(t_list *tokens);
int		run_redirs(t_list *tokens);
int		run_built_in(char **av, t_list *chunk, int log);
int		run_built_in_sup(char **av, t_list *chunk);
void	run_cmd(char **av, t_list *chunk);
int		get_fd_tail_1(t_list *chunk);
int		get_fd_tail_0(t_list *chunk);
int		get_fd_head_0(t_list *chunk);
int		get_fd_head_1(t_list *chunk);
void	close_unused_pipes(t_list *tokens, int head_0, int tail_1);
void	setup_stdio(int fd_head_0, int fd_tail_1, \
	int fd_head_1, int fd_tail_0);
void	skip_to_next_chunk(t_list **current);
int		run_out_fork(t_list *tokens);
void	run_in_fork(t_ints i, t_list *current, char ***av);
void	assign_fds(t_list *current, t_ints *i);
void	close_fds(t_ints i);
int		run_cmds(t_list *tokens);
void	clean_in_fork(t_list **tokens);
int		exit_sub(int tokens_exit);

#endif
