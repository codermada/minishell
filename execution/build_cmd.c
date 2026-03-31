/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toloandr <toloandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 19:59:17 by toloandr          #+#    #+#             */
/*   Updated: 2025/08/04 21:44:10 by toloandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static int	get_ac(t_list *tokens)
{
	int		ac;
	t_list	*current;
	int		*type;

	current = tokens;
	ac = 0;
	while (current)
	{
		type = &((t_token *)current->data)->type;
		if (*type == ARG)
			ac++;
		current = current->next_;
	}
	return (ac);
}

char	**build_cmd(t_list *tokens)
{
	int		i;
	t_list	*current;
	int		ac;
	char	**av;

	i = 0;
	current = tokens;
	ac = get_ac(tokens);
	av = malloc(sizeof(char *) * (ac + 1));
	if (!av)
		return (NULL);
	while (current)
	{
		if (((t_token *)current->data)->type == ARG)
		{
			if (str_len(((t_token *)current->data)->token) > 0)
			{
				av[i] = ((t_token *)current->data)->token;
				i++;
			}
		}
		current = current->next_;
	}
	av[i] = NULL;
	return (av);
}
