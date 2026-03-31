/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toloandr <toloandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 19:39:20 by toloandr          #+#    #+#             */
/*   Updated: 2025/07/26 13:51:13 by toloandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "basic_utils.h"

void	put_str(char *str)
{
	write(1, str, str_len(str));
}

void	put_str_fd(int fd, char *str)
{
	write(fd, str, str_len(str));
}

void	put_str_colored(int fd, char *str, \
char *color)
{
	if (!str || !color)
		return ;
	if (COLOR == 1)
		write(fd, color, str_len(color));
	write(fd, str, str_len(str));
	if (COLOR == 1)
		write(fd, RST, str_len(RST));
}

void	print_welcome(void)
{
	static char	*welcome = "·▄▄▄▄• ▄▌▄▄▄  ▪        ▄• ▄▌.▄▄ · \n \
▐▄▄·█▪██▌▀▄ █·██ ▪     █▪██▌▐█ ▀. \n \
██▪ █▌▐█▌▐▀▀▄ ▐█· ▄█▀▄ █▌▐█▌▄▀▀▀█▄\n \
██▌.▐█▄█▌▐█•█▌▐█▌▐█▌.▐▌▐█▄█▌▐█▄▪▐█\n \
▀▀▀  ▀▀▀ .▀  ▀▀▀▀ ▀█▄▀▪ ▀▀▀  ▀▀▀▀ \n \
By: toloandr, nnomenja\n";

	put_str_colored(STDOUT_FILENO, welcome, COLOR_03BAFC);
}
