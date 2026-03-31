/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_operator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toloandr <toloandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 19:51:15 by toloandr          #+#    #+#             */
/*   Updated: 2025/07/17 21:16:17 by toloandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int	is_operator(char *str)
{
	if (str_cmp(str, "|"))
		return (PIPE);
	else if (str_cmp(str, "<"))
		return (INFILE);
	else if (str_cmp(str, ">"))
		return (OUTFILE);
	else if (str_cmp(str, ">>"))
		return (APPEND);
	else if (str_cmp(str, "<<"))
		return (HEREDOC);
	else
		return (-1);
}
