/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_input.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toloandr <toloandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 05:58:44 by toloandr          #+#    #+#             */
/*   Updated: 2025/08/01 14:40:11 by toloandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROCESS_INPUT_H
# define PROCESS_INPUT_H

# include "basic_utils.h"

int		is_pipe_(char c);
int		is_redout_or_append(char c, char c_);
int		is_redin_or_heredoc(char c, char c_);
int		is_dollar_question_mark(char c, char c_);
int		process_exit_status(char **res, char *input, \
int *i, int exit_status);
int		process_operators(char **res, char *input, int *i, int exit_status);
char	*new_input(char *input, int exit_status);
char	*i_to_a(unsigned long long n);

#endif