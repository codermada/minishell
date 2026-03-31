/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toloandr <toloandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 22:35:34 by toloandr          #+#    #+#             */
/*   Updated: 2025/08/03 18:45:18 by toloandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "basic_utils.h"

void	print_error(char *err)
{
	if (COLOR)
		write(STDERR_FILENO, RED, str_len(RED));
	write(STDERR_FILENO, err, str_len(err));
	if (COLOR)
		write(STDERR_FILENO, RST, str_len(RST));
	write(STDERR_FILENO, "\n", 1);
}

void	print_error_(char *info, char *err, int nl)
{
	put_str_fd(STDERR_FILENO, "minishell: ");
	put_str_fd(STDERR_FILENO, info);
	put_str_fd(STDERR_FILENO, ": ");
	put_str_fd(STDERR_FILENO, err);
	if (nl == 1)
		write(STDERR_FILENO, "\n", 1);
}
