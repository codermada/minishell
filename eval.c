/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toloandr <toloandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 10:24:13 by toloandr          #+#    #+#             */
/*   Updated: 2025/08/06 16:03:05 by toloandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "dictionary.h"
#include "lexer.h"
#include "parser.h"
#include "execution.h"

static void	preprocess_tokens(char *input, t_list **tokens, t_dict **env_dict)
{
	char	*expanded;

	*tokens = lexing(input);
	expanded = str_from_tokens(*tokens, *env_dict);
	free_tokens(tokens);
	*tokens = lexing(expanded);
	free(expanded);
}

// #include <stdio.h>

// void print_token_list(t_list *head)
// {
//     t_list *tmp = head;

//     printf("===== TOKEN LIST =====\n");

//     while (tmp)
//     {
//         t_token *tok = (t_token *)tmp->data;

//         printf("[id:%d | chunk:%d]\n", tmp->id, tmp->chunk_id);

//         printf("  pipe fd: [%d -> %d]\n", tmp->fd[0], tmp->fd[1]);

//         if (tok)
//         {
//             printf("  token type: %d\n", tok->type);
//             printf("  token: \"%s\"\n", tok->token ? tok->token : "(null)");
//             printf("  token fd: %d\n", tok->fd);
//         }
//         else
//         {
//             printf("  token: (null)\n");
//         }

//         printf("----------------------\n");

//         tmp = tmp->next;
//     }

//     printf("======================\n");
// }

t_exit	eval(char *input, t_dict **env_dict, int fd_history)
{
	t_list	*tokens;
	t_exit	e;

	e.status = 0;
	preprocess_tokens(input, &tokens, env_dict);
	if (!tokens)
		return (free_tokens(&tokens), \
		(t_exit){0, -1});
	if (!check_tokens(tokens) || !balanced_quotes(input))
		return (free_tokens(&tokens), \
		(t_exit){2, -1});
	tokens->input = input;
	tokens->history_fd = fd_history;
	process_tokens(&tokens, env_dict);
	e.status = run_heredocs(tokens);
	if (e.status > 0)
	{
		e = exit_status(tokens->exit, e.status);
		if (e.status == 130)
			return (clean_up(&tokens), (t_exit){e.status, -1});
	}
	e.status = run_cmds(tokens);
	// print_token_list(tokens);
	e = exit_status(tokens->exit, e.status);
	clean_up(&tokens);
	return (e);
}
