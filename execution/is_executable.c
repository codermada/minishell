/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_executable.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toloandr <toloandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 12:25:21 by toloandr          #+#    #+#             */
/*   Updated: 2025/07/27 01:21:09 by toloandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

char	*is_in_path(char *cmd, t_dict *env_dict)
{
	char	*path;
	char	*path_cmd;
	char	*var_path;
	char	*dup_var_path;

	if (!get_item(env_dict, "PATH", cmp))
		return (NULL);
	var_path = (char *)get_item(env_dict, "PATH", cmp)->value;
	dup_var_path = str_dup(var_path);
	path = str_tok(dup_var_path, ":");
	while (path)
	{
		path = str_dup(path);
		path_cmd = str_n_join(path, "/", 1);
		path_cmd = str_n_join(path_cmd, cmd, str_len(cmd));
		if ((access(path_cmd, X_OK) == 0) \
			|| (access(path_cmd, F_OK) == 0))
			return (free(dup_var_path), path_cmd);
		free(path_cmd);
		path = str_tok(NULL, ":");
	}
	return (free(dup_var_path), NULL);
}

static int	check_path_executable(char *cmd, char **path_cmd)
{
	struct stat	sb;

	*path_cmd = NULL;
	if (stat(cmd, &sb) == 0 && S_ISDIR(sb.st_mode))
		return (126);
	if (access(cmd, F_OK) != 0)
		return (127);
	if (access(cmd, X_OK) != 0)
		return (126);
	*path_cmd = str_dup(cmd);
	return (0);
}

int	is_executable(char *cmd, t_dict *env_dict, char **path_cmd)
{
	char	*tmp;

	*path_cmd = NULL;
	if (!cmd)
		return (127);
	if (is_path(cmd) > 0)
		return (check_path_executable(cmd, path_cmd));
	tmp = is_in_path(cmd, env_dict);
	if (!tmp)
		return (127);
	if (access(tmp, X_OK) == 0)
	{
		*path_cmd = tmp;
		return (0);
	}
	free(tmp);
	return (126);
}
