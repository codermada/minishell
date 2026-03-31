/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toloandr <toloandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 06:49:02 by toloandr          #+#    #+#             */
/*   Updated: 2025/07/29 21:40:57 by toloandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "lexer.h"

void	close_fd_0_1(t_list *tokens);
void	close_fd_1(t_list *tokens);
void	close_fd_pipes(t_list *tokens);

void	heredoc_handle_sigint(int sig);
void	heredoc(int fd, char *delim, t_list **tokens, int hd_delim_quoted);

void	split_tokens(t_list *tokens);
int		run_heredocs(t_list *tokens);

#endif