/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toloandr <toloandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 11:36:43 by toloandr          #+#    #+#             */
/*   Updated: 2025/07/21 11:47:32 by toloandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "basic_utils.h"

pid_t	fork_1(void)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		print_error("fork error");
		return (-1);
	}
	return (pid);
}
