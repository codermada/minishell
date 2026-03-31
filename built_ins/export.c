/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toloandr <toloandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 17:38:23 by toloandr          #+#    #+#             */
/*   Updated: 2025/08/07 02:52:13 by toloandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_ins.h"

static int	char_in_str(char c, char *str)
{
	while (*str)
	{
		if (c == *str)
			return (1);
		str++;
	}
	return (0);
}

static void	export_var_if_does_not_exist(char *value, \
t_dict **env_dict, char *key, char *av_i)
{
	if (value != NULL)
		dict_add(env_dict, str_dup(key), str_dup(value), cmp);
	else
		dict_add(env_dict, str_dup(key), str_dup(""), cmp);
	get_item(*env_dict, key, cmp)->exported = 1;
	if (char_in_str('=', av_i) == 1 || value)
		get_item(*env_dict, key, cmp)->assigned = 1;
	else
		get_item(*env_dict, key, cmp)->assigned = 0;
}

static void	export_var_if_exist(char *value, t_dict **env_dict, \
char *key, char *av_i)
{
	t_dict	*item;

	item = get_item(*env_dict, key, cmp);
	if (value != NULL)
	{
		if (!char_in_str('=', av_i))
			return ;
		((char *)item->key)[0] = '\0';
		dict_add(env_dict, str_dup(key), str_dup(value), cmp);
	}
	else
	{
		if (!char_in_str('=', av_i))
			return ;
		((char *)item->key)[0] = '\0';
		dict_add(env_dict, str_dup(key), str_dup(""), cmp);
	}
	get_item(*env_dict, key, cmp)->exported = 1;
	if (item->assigned)
		get_item(*env_dict, key, cmp)->assigned = 1;
	if (char_in_str('=', av_i))
		get_item(*env_dict, key, cmp)->assigned = 1;
	else
		get_item(*env_dict, key, cmp)->assigned = 0;
}

static void	export_var(char **value, t_dict **env_dict, \
char *key, char *av_i)
{
	*value = str_tok(NULL, "");
	if (!get_item(*env_dict, key, cmp))
		export_var_if_does_not_exist(*value, \
		env_dict, key, av_i);
	else
		export_var_if_exist(*value, \
		env_dict, key, av_i);
}

int	export(char **av, t_dict **env_dict, t_list *tokens)
{
	int		i;
	char	*dup_av_i;
	char	*key;
	char	*value;

	i = 1;
	if (get_arg_count(av) == 1)
		print_env(*env_dict);
	while (av[i])
	{
		dup_av_i = str_dup(av[i]);
		key = str_tok(dup_av_i, "=");
		if (!check_key(key, &i, tokens, &dup_av_i))
			continue ;
		if (!check_av_i(av[i], &i, tokens, &dup_av_i))
			continue ;
		export_var(&value, env_dict, key, av[i]);
		free(dup_av_i);
		i++;
	}
	return (0);
}
