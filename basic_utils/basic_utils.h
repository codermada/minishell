/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toloandr <toloandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 19:43:30 by toloandr          #+#    #+#             */
/*   Updated: 2025/08/03 17:56:04 by toloandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASIC_UTILS_H
# define BASIC_UTILS_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>

# define Y   "\x1b[33m"
# define G   "\x1b[32m"
# define C   "\x1b[36m"
# define COLOR_03BAFC "\x1b[38;2;3;186;252m"
# define RED "\x1b[31m"
# define RST "\x1b[0m"
# define COLOR	0

int			str_len(char *str);
int			str_cmp(char *str1, char *str2);
int			str_cmp_(char *str1, char *str2);
char		*str_dup(char *str);
char		*str_dup_delim(char *str);
char		*str_n_join(char *str, char *to_join, int n);
void		str_cat(char *dest, char *src);
void		str_cpy(char *dest, char *src);
char		*str_tok(char *str, const char *delim);
int			is_space(char c);
int			is_alpha(int c);
int			is_alnum(int c);
void		print_error(char *err);
void		print_error_(char *info, char *err, int nl);
void		put_str(char *str);
void		put_str_fd(int fd, char *str);
void		put_str_colored(int fd, char *str, \
char *color);
void		print_welcome(void);
pid_t		fork_1(void);
int			ft_atoi(const char *nptr);
long long	ft_atol(const char *nptr);

#endif