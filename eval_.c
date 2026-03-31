/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toloandr <toloandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 17:41:40 by toloandr          #+#    #+#             */
/*   Updated: 2025/08/05 01:01:14 by toloandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "dictionary.h"
#include "lexer.h"
#include "parser.h"
#include "execution.h"

t_list	*get_list(t_list *list)
{
	static t_list	*data = NULL;

	if (list)
		data = list;
	return (data);
}

t_exit	exit_status(int exit, int status)
{
	if (exit == -2)
		return ((t_exit){2, -1});
	else if (exit == -1)
		return ((t_exit){1, -1});
	else if (exit >= 0)
		return ((t_exit){exit, exit});
	return ((t_exit){status, -1});
}

void	process_tokens(t_list **tokens, t_dict **env_dict)
{
	(void)env_dict;
	get_list(*tokens);
	(*tokens)->env_dict = env_dict;
	(*tokens)->env = create_env(*env_dict);
	tag_quotes(*tokens);
	remove_quotes(*tokens);
	tag_all(*tokens);
	split_tokens(*tokens);
}

void	clean_up(t_list **tokens)
{
	close_fd_0_1(*tokens);
	free_env((*tokens)->env);
	free_tokens(tokens);
}
