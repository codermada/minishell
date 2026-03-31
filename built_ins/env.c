/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toloandr <toloandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 16:06:39 by toloandr          #+#    #+#             */
/*   Updated: 2025/08/06 16:21:46 by toloandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_ins.h"

static void	print_env_item(char *key, char *value, int assigned)
{
	if (assigned)
	{
		put_str_fd(STDOUT_FILENO, key);
		put_str_fd(STDOUT_FILENO, "=");
		put_str_fd(STDOUT_FILENO, value);
		put_str_fd(STDOUT_FILENO, "\n");
	}
}

void	print_env_items(t_dict *env_dict)
{
	char	*key;
	char	*value;
	t_dict	*current;

	current = env_dict;
	while (current)
	{
		key = current->key;
		if (key[0] == '\0')
		{
			current = current->next;
			continue ;
		}
		value = current->value;
		if (current->id < env_dict->initial_len)
			print_env_item(key, value, 1);
		else
			print_env_item(key, value, current->assigned);
		current = current->next;
	}
}

void	env(char **av, t_list *tokens)
{
	t_dict	*env_dict;

	if (get_arg_count(av) > 1)
	{
		print_error("minishell: too many arguments");
		tokens->exit = -2;
		return ;
	}
	env_dict = *(tokens->env_dict);
	print_env_items(env_dict);
}
