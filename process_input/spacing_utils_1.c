/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spacing_utils_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toloandr <toloandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 18:10:18 by toloandr          #+#    #+#             */
/*   Updated: 2025/07/18 12:13:25 by toloandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process_input.h"

int	is_pipe_(char c)
{
	if (c == '|')
		return (1);
	return (0);
}

int	is_redout_or_append(char c, char c_)
{
	if ((c == '>') && (c_ != '>'))
	{
		return (1);
	}
	else if ((c == '>') && (c_ == '>'))
	{
		return (2);
	}
	return (0);
}

int	is_redin_or_heredoc(char c, char c_)
{
	if ((c == '<') && (c_ != '<'))
	{
		return (1);
	}
	else if ((c == '<') && (c_ == '<'))
	{
		return (2);
	}
	return (0);
}

int	is_dollar_question_mark(char c, char c_)
{
	if ((c == '$') && (c_ == '?'))
		return (1);
	return (0);
}
