/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spacing_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toloandr <toloandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 18:11:32 by toloandr          #+#    #+#             */
/*   Updated: 2025/07/18 14:36:11 by toloandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process_input.h"

static int	process_pipe(char **res, char *input, int *i)
{
	if (is_pipe_(input[*i]))
	{
		*res = str_n_join(*res, " | ", 3);
		(*i)++;
		return (1);
	}
	return (0);
}

static int	process_redout_append(char **res, char *input, int *i)
{
	if (is_redout_or_append(input[*i], input[*i + 1]) == 1)
	{
		*res = str_n_join(*res, " > ", 3);
		(*i)++;
		return (1);
	}
	if (is_redout_or_append(input[*i], input[*i + 1]) == 2)
	{
		*res = str_n_join(*res, " >> ", 4);
		*i += 2;
		return (1);
	}
	return (0);
}

static int	process_redin_heredoc(char **res, char *input, int *i)
{
	if (is_redin_or_heredoc(input[*i], input[*i + 1]) == 1)
	{
		*res = str_n_join(*res, " < ", 3);
		(*i)++;
		return (1);
	}
	if (is_redin_or_heredoc(input[*i], input[*i + 1]) == 2)
	{
		*res = str_n_join(*res, " << ", 4);
		*i += 2;
		return (1);
	}
	return (0);
}

int	process_exit_status(char **res, char *input, \
int *i, int exit_status)
{
	char	*e_s;

	if (is_dollar_question_mark(input[*i], \
input[*i + 1]) == 1)
	{
		e_s = i_to_a(exit_status);
		*res = str_n_join(*res, e_s, str_len(e_s));
		*i += 2;
		return (free(e_s), 1);
	}
	return (0);
}

int	process_operators(char **res, char *input, \
int *i, int exit_status)
{
	(void)exit_status;
	if (process_pipe(res, input, i))
		return (1);
	if (process_redout_append(res, input, i))
		return (1);
	if (process_redin_heredoc(res, input, i))
		return (1);
	if (process_exit_status(res, input, i, exit_status))
		return (1);
	return (0);
}
