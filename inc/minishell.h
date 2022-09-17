/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 23:56:44 by brda-sil          #+#    #+#             */
/*   Updated: 2022/09/17 04:28:39 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/* ########################################################################## */
/* INCLUDE */
/* ####### */

# include "libft.h"

/*
O_RDONLY
*/
# include <fcntl.h>
/*
SIGINT
*/
# include <signal.h>
/*
waitpid
*/
# include <sys/wait.h>
# include <stdio.h>
/*
readline
*/
# include <readline/readline.h>

/* ########################################################################## */

/* ########################################################################## */
/* CONFIG */
/* ###### */

# ifndef DEBUG
#  define DEBUG 0
# endif
# define VRAI 42

# define LOG_FD			3
# define GREEN_PLUS		"[\e[38;5;82m+\e[0m]"
# define RED_MINUS		"[\e[38;5;196m-\e[0m]"
# define ORANGE_STAR	"[\e[38;5;214m*\e[0m]"

/* ########################################################################## */

/* ########################################################################## */
/* STRUCT */
/* ###### */

typedef struct s_main
{
	char				*prompt;
	char				*line_buffer;
	t_list				*line_splitted;
	struct s_block		*line_block;
	struct s_context	*context;
	struct s_lst_env	*env;
	int					last_return_value;
}			t_main;

// EXEC ENGINE PART

typedef struct s_cmd
{
	char					*path;
	char					**command;
	pid_t					cmd_pid;
	struct s_redirection	*in_redir;
	struct s_redirection	*out_redir;
	struct s_redirection	*double_in_redir;
	struct s_redirection	*double_out_redir;
	int						return_value;
}							t_cmd;

typedef struct s_redirection
{
	char					*content;
	int						file;
	struct s_redirection	*next;
}				t_redirection;

typedef struct s_context
{
	int		cmd_nb;
	int		cmd_id;
	int		pipe_id;
	t_cmd	**cmd;
	int		**pipes;
	int		default_in;
	int		default_out;
}			t_context;

// PARSE CMD PART

enum e_block_id
{
	STR,
	PIPE,
	OUT_FORWARD,
	DBL_OUT_FORWARD,
	IN_FORWARD,
	DELIMITER,
	SPACEE,
	ERROR
};

typedef struct s_block
{
	char			*block;
	int				block_id;
	struct s_block	*next;
}					t_block;

typedef struct s_lst_env{
	void	*key;
	void	*value;
	int		index;
	void	*next;
}			t_lst_env;

/* ########################################################################## */

/* ########################################################################## */
/* FILES */
/* ##### */

// builtins/env.c
void			print_env(t_lst_env *envlst);

// builtins/export.c
void			print_export(t_lst_env *envlst);
void			unlink_key_value(char *var_env, char **key, char **value);

// dataset/free.c
void			free_char_pointer_pointer(char **str);
void			free_config(t_main *config);
void			free_entry(t_main *config);

// dataset/init.c
char			*init_get_prompt(void);
int				init_config(t_main *config, char **envp);
int				init_entry(t_main *config, char **envp);
int				init_signal(void);

// debug/debug_init_redirection.c
void			debug_init_redirection(t_main *config);

// debug/debug_parse.c
void			debug_parse(t_main *config);
void			debug_print_line_block(t_block *line_block);

// minishell.c
char			**do_something_with_argv(char **argv);

// shell/exec/dataset/free_exec.c
void			free_exec_entry(t_context *context);

// shell/exec/dataset/init_context.c
int				init_cmd(t_main *config);
int				init_context(t_main *config);
int				init_context_entry(t_main *config);
size_t			get_number_of_command(t_main *config);

// shell/exec/dataset/init_redirection.c
t_redirection	*redir_new(char *content);
void			init_redirection(t_main *config);
void			init_redirection_lst(t_redirection **lst, char *content);
void			redir_addback(t_redirection **lst, t_redirection *new);

// shell/exec/exec/exec_prepare.c
void			exec_prepare_between(t_context *config);
void			exec_prepare_entry(t_context *config);
void			exec_prepare_first(t_context *config);
void			exec_prepare_last(t_context *config);
void			exec_prepare_pipe(t_context *config);

// shell/exec/exec/exec_prepare_redirection.c
void			exec_prepare_in_double_file(t_context *config);
void			exec_prepare_in_file(t_context *config);
void			exec_prepare_out_double_file(t_context *config);
void			exec_prepare_out_file(t_context *config);
void			exec_prepare_redirection(t_context *config);

// shell/exec/exec/execute.c
int				exec_entry(t_context *config);
void			exec_command(t_context *config);

// shell/exec/exec/utils.c
void			close_all_pipes(t_context *config);
void			print_command_not_found(t_context *config);
void			wait_for_all(t_context *config);

// shell/exec/exec_engine.c
void			exec_engine(t_main *config);

// shell/loop.c
int				main_loop(t_main *config);

// shell/parsing/get_block.c
t_block			*ft_lstadd_back_block(t_block **lst, t_block *new);
t_block			*ft_lstnew_block(void *content);
void			get_block(t_block *input);
void			join_all(t_block *input);
void			trim_quotes(t_block *input);

// shell/parsing/identify_pipe.c
int				is_in_forward(t_block *input);
int				is_out_forward(t_block *input);
int				is_pipe(t_block *input);
void			identify_redirection(t_block *input);

// shell/parsing/parse_entry.c
void			parse_cmd_entry(t_main *config);

// shell/parsing/replace_dollar.c
char			*find_key(char **input, t_lst_env *env);
char			*replace_key(char *input, t_lst_env *env);
void			parse_replace_dollar(t_main *config, t_lst_env *env);

// shell/signal_handler.c
void			handle_sig_int(void);
void			handle_sig_quit(void);
void			signal_handler(int signal_code);

// utils/convert_list.c
t_block			*convert_list(t_list *input);

// utils/env_export_utils_1.c
t_lst_env		*env_to_lst(char **env);
void			export_var_to_env(t_lst_env **envlst, char *var);
void			index_env_lst(t_lst_env **envlst);
void			index_env_lst2(t_lst_env *lst, t_lst_env **tmp, t_lst_env **tmp2, int *i);

// utils/env_export_utils_2.c
int				ft_strcmp_env(char *s1, char *s2);
t_lst_env		*ft_lstadd_back_env(t_lst_env **lst, t_lst_env *new);
t_lst_env		*ft_lstnew_env(void *env);

// utils/ft_better_split.c
t_list			*ft_better_split(char *s);
void			manage_quotes(char **s, char c, t_list **input);
void			manage_strings(char **s, t_list **input);
void			manage_symbols(char **s, char c, t_list **input);

// utils/ft_better_strjoin.c
char			*ft_better_strjoin(char *s1, char *s2);

// utils/ft_splitb.c
char			**ft_splitb(char *s, char delim, char *encl);
char			**ft_splitb_get_words(char *s, char delim, char *encl, int tab_size);
int				ft_splitb_get_size(char *str, char delim, char *encl);
int				ft_splitb_get_word(char **str, char delim, char *encl);

// utils/get_path.c
char			**get_path(char **env);
char			*get_cmd_path(char *name, char **path);

/* ########################################################################## */

#endif
