# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nnomenja <nnomenja@student.42antananari    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/13 16:50:51 by toloandr          #+#    #+#              #
#    Updated: 2025/08/08 12:12:12 by nnomenja         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CFLAGS = -Wall -Wextra -Werror -I. -Ibasic_utils -Iprocess_input -Ienv_utils -Ilexer -Ilinked_list -Iparser -Ibuilt_ins -Iexecution -Ihistory

MAIN_SRCS = main.c main_utils.c balanced_quotes.c eval.c eval_.c

HISTORY_DIR = history
HISTORY_SRCS = $(HISTORY_DIR)/init_history.c \
			   $(HISTORY_DIR)/utils_history.c \

BASIC_UTILS_DIR = basic_utils
BASIC_UTILS_SRCS = $(BASIC_UTILS_DIR)/str_cmp.c \
				   $(BASIC_UTILS_DIR)/str_len.c \
				   $(BASIC_UTILS_DIR)/str_dup.c \
				   $(BASIC_UTILS_DIR)/str_cat.c \
				   $(BASIC_UTILS_DIR)/str_cpy.c \
				   $(BASIC_UTILS_DIR)/str_dup_delim.c \
				   $(BASIC_UTILS_DIR)/str_n_join.c \
				   $(BASIC_UTILS_DIR)/str_tok.c \
				   $(BASIC_UTILS_DIR)/check_char.c \
				   $(BASIC_UTILS_DIR)/print_error.c \
				   $(BASIC_UTILS_DIR)/put_str.c \
				   $(BASIC_UTILS_DIR)/fork_1.c \
				   $(BASIC_UTILS_DIR)/ft_atoi.c \
				   $(BASIC_UTILS_DIR)/ft_atol.c

PROCESS_INPUT_DIR = process_input
PROCESS_INPUT_SRCS = $(PROCESS_INPUT_DIR)/spacing.c \
					 $(PROCESS_INPUT_DIR)/spacing_utils_1.c \
					 $(PROCESS_INPUT_DIR)/spacing_utils_2.c \
					 $(PROCESS_INPUT_DIR)/exit_status.c \

ENV_UTILS_DIR = env_utils
ENV_UTILS_SRCS = $(ENV_UTILS_DIR)/build_env_item.c \
				 $(ENV_UTILS_DIR)/get_item.c \
				 $(ENV_UTILS_DIR)/cmp.c \
				 $(ENV_UTILS_DIR)/env_utils.c \
				 $(ENV_UTILS_DIR)/split_env_item.c \
				 $(ENV_UTILS_DIR)/dict_add.c \
				 $(ENV_UTILS_DIR)/free_dict.c \
			     $(ENV_UTILS_DIR)/system_env_to_dict.c \
				 $(ENV_UTILS_DIR)/create_env.c \
				 $(ENV_UTILS_DIR)/sort_env.c \
				 $(ENV_UTILS_DIR)/copy_dict.c \
				 $(ENV_UTILS_DIR)/sort_dict.c

LINKED_LIST_DIR = linked_list
LINKED_LIST_SRCS = $(LINKED_LIST_DIR)/free_list.c \
				   $(LINKED_LIST_DIR)/list_append.c \
				   $(LINKED_LIST_DIR)/remove_head.c \
				   $(LINKED_LIST_DIR)/remove_tail.c

LEXER_DIR = lexer
LEXER_SRCS = $(LEXER_DIR)/is_operator.c \
			 $(LEXER_DIR)/lexer.c \
			 $(LEXER_DIR)/check_tokens.c \
			 $(LEXER_DIR)/tag_quotes.c \
			 $(LEXER_DIR)/tag_all.c \
			 $(LEXER_DIR)/expand_var_envs.c \
			 $(LEXER_DIR)/expand_var_envs_1.c \
			 $(LEXER_DIR)/remove_quotes.c

PARSER_DIR = parser
PARSER_SRCS = $(PARSER_DIR)/parser.c \
			  $(PARSER_DIR)/heredoc.c \
			  $(PARSER_DIR)/heredoc_utils.c

BUILT_INS_DIR = built_ins
BUILT_INS_SRCS = $(BUILT_INS_DIR)/echo.c \
				 $(BUILT_INS_DIR)/cd.c \
				 $(BUILT_INS_DIR)/pwd.c \
				 $(BUILT_INS_DIR)/env.c \
				 $(BUILT_INS_DIR)/unset.c \
				 $(BUILT_INS_DIR)/export.c \
				 $(BUILT_INS_DIR)/export_utils_1.c \
				 $(BUILT_INS_DIR)/export_utils_2.c \
				 $(BUILT_INS_DIR)/exit.c

EXECUTION_DIR = execution
EXECUTION_SRCS = $(EXECUTION_DIR)/is_executable.c \
				 $(EXECUTION_DIR)/is_path.c \
				 $(EXECUTION_DIR)/is_directory.c \
				 $(EXECUTION_DIR)/is_built_in.c \
				 $(EXECUTION_DIR)/build_cmd.c \
				 $(EXECUTION_DIR)/run_redirs.c \
				 $(EXECUTION_DIR)/run_cmd.c \
				 $(EXECUTION_DIR)/run_cmds.c \
				 $(EXECUTION_DIR)/run_cmds_utils_1.c \
				 $(EXECUTION_DIR)/run_cmds_utils_2.c \
				 $(EXECUTION_DIR)/run_cmds_utils_3.c

SRCS = $(MAIN_SRCS) \
	   $(BASIC_UTILS_SRCS) \
	   $(PROCESS_INPUT_SRCS) \
	   $(ENV_UTILS_SRCS) \
	   $(LINKED_LIST_SRCS) \
	   $(LEXER_SRCS) \
	   $(PARSER_SRCS) \
	   $(BUILT_INS_SRCS) \
	   $(EXECUTION_SRCS) \
	   $(HISTORY_SRCS)
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	cc $(CFLAGS) $(OBJS) -lreadline -o $(NAME)

%.o: %.c
	cc $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)
	rm -rf minishell_history
	rm -rf readline.supp

debug: $(NAME)
	@echo "{" > readline.supp
	@echo "    ignore_libreadline_leaks" >> readline.supp
	@echo "    Memcheck:Leak" >> readline.supp
	@echo "    ..." >> readline.supp
	@echo "    obj:*/libreadline.so.*" >> readline.supp
	@echo "}" >> readline.supp
	valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes --suppressions=readline.supp ./minishell


re: fclean all
