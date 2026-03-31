/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toloandr <toloandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 19:41:00 by toloandr          #+#    #+#             */
/*   Updated: 2025/08/05 01:01:06 by toloandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "minishell.h"
# include "basic_utils.h"
# include "list.h"
# include "dictionary.h"

# define PIPE 0
# define INFILE 1
# define OUTFILE 2
# define APPEND 3
# define HEREDOC 4
# define SQ 10
# define DQ 20

# define IN_FILENAME 6001
# define OUT_FILENAME 6002
# define APPEND_FILENAME 6003
# define DELIM 6004

# define ARG 777

typedef struct s_token
{
	int		type;
	int		fd;
	char	*token;
}	t_token;

int		check_tokens(t_list *tokens);
int		is_operator(char *str);
char	*str_from_tokens(t_list *tokens, t_dict *env_dict);
t_list	*lexing(char *input);
int		should_expand(char c, char c_, int cond);
char	*expand_variable(char **token_ptr, t_dict *env);
char	*expand(char *token, t_dict *env);
char	*expand_(char *token, t_dict *env);
void	remove_quotes(t_list *tokens);
void	free_tokens(t_list **tokens);

void	tag_quotes(t_list *tokens);
void	tag_all(t_list *tokens);

#endif