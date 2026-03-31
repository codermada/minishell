/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_built_in.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toloandr <toloandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 16:32:22 by toloandr          #+#    #+#             */
/*   Updated: 2025/07/19 20:19:57 by toloandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

int	is_built_in(char *command)
{
	if (str_cmp("echo", command))
		return (BUILT_IN_ECHO);
	else if (str_cmp("cd", command))
		return (BUILT_IN_CD);
	else if (str_cmp("pwd", command))
		return (BUILT_IN_PWD);
	else if (str_cmp("export", command))
		return (BUILT_IN_EXPORT);
	else if (str_cmp("unset", command))
		return (BUILT_IN_UNSET);
	else if (str_cmp("env", command))
		return (BUILT_IN_ENV);
	else if (str_cmp("exit", command))
		return (BUILT_IN_EXIT);
	else
		return (-1);
}
