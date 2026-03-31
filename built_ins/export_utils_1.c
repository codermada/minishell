/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toloandr <toloandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 14:15:00 by toloandr          #+#    #+#             */
/*   Updated: 2025/08/06 15:01:00 by toloandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_ins.h"

static void	print_(char *key, char *value, int assigned)
{
	put_str_fd(STDOUT_FILENO, "declare -x ");
	put_str_fd(STDOUT_FILENO, key);
	if (assigned)
	{
		put_str_fd(STDOUT_FILENO, "=");
		put_str_fd(STDOUT_FILENO, "\"");
		put_str_fd(STDOUT_FILENO, value);
		put_str_fd(STDOUT_FILENO, "\"");
	}
	put_str_fd(STDOUT_FILENO, "\n");
}

void	print_env(t_dict *env_dict)
{
	char	*key;
	char	*value;
	t_dict	*current;
	t_dict	*cpy;

	copy_dict(env_dict, &cpy);
	sort_dict(&cpy);
	current = cpy;
	while (current)
	{
		key = current->key;
		if (key[0] == '\0' || str_cmp(key, "_"))
		{
			current = current->next;
			continue ;
		}
		value = current->value;
		if (current->id < cpy->initial_len - 1)
			print_(key, value, 1);
		else
			print_(key, value, current->assigned);
		current = current->next;
	}
	free_dict(&cpy, 1, 1);
}

int	is_valid_env_key(char *str)
{
	int	i;

	if (!str || !str[0])
		return (0);
	i = 0;
	if (str[i] == '=')
		return (0);
	while (str[i] && str[i] != '=')
	{
		if (i == 0 && !(is_alpha(str[i]) || str[i] == '_'))
			return (0);
		if (!(is_alnum(str[i]) || str[i] == '_'))
			return (0);
		i++;
	}
	if (str[i] == '=' && str[i + 1] == '\0')
		return (0);
	return (1);
}

void	print_invalid_identifier_error(int *i, t_list *tokens)
{
	print_error("minishell: export: not a valid identifier");
	(*i)++;
	tokens->exit = -1;
}
