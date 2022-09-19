/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 23:56:44 by brda-sil          #+#    #+#             */
/*   Updated: 2022/09/19 16:44:18 by brda-sil         ###   ########.fr       */
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
/*
add_history
*/
# include <readline/history.h>

/* ########################################################################## */

/* ########################################################################## */
/* CONFIG */
/* ###### */

# ifndef DEBUG
#  define DEBUG 0
# endif
# define VRAI 42

# define LOG_FD			420
# define GREEN_PLUS		"[\e[38;5;82m+\e[0m]"
# define RED_MINUS		"[\e[38;5;196m-\e[0m]"
# define ORANGE_STAR	"[\e[38;5;214m*\e[0m]"

/* ########################################################################## */

/* ########################################################################## */
/* STRUCT */
/* ###### */

typedef struct s_main
{
	char				*base_prompt;
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
	t_list					*tmp_command;
	char					*path;
	char					**command;
	pid_t					cmd_pid;
	struct s_redirection	*in_redir;
	struct s_redirection	*out_redir;
	int						return_value;
}							t_cmd;

typedef struct s_redirection
{
	char					*content;
	int						is_double;
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
	char	**path;
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

// dataset/free/cmds.c
void			free_cmd(t_cmd *cmd);
void			free_cmds(t_context *context);

// dataset/free/config.c
void			free_config_entry(t_main *config);

// dataset/free/exec.c
void			free_exec_entry(t_main *config);

// dataset/free/pipes.c
void			free_pipes(t_context *context);

// dataset/free/utils/char_pointer_pointer.c
void			free_char_pointer_pointer(char **str);

// dataset/free/utils/list.c
void			free_t_block(t_block *lst);
void			free_t_list(t_list *lst);
void			free_t_list_env(t_lst_env *lst);
void			free_t_redirection(t_redirection *lst);

// dataset/init/config.c
int				init_config(t_main *config, char **envp);
int				init_config_entry(t_main *config, char **envp);

// dataset/init/context.c
int				init_cmd(t_main *config);
int				init_context(t_main *config);
int				init_context_entry(t_main *config);
size_t			get_number_of_command(t_main *config);

// dataset/init/redirection.c
t_redirection	*redir_new(char *content, int is_double);
void			init_redirection(t_main *config);
void			init_redirection_lst(t_redirection **lst, char *content, int is_double);
void			redir_addback(t_redirection **lst, t_redirection *new);

// dataset/init/signal.c
int				init_signal(void);

// debug/debug_init_redirection.c
void			debug_init_redirection(t_main *config);
void			debug_print_redir_1(t_redirection *lst, int mode, int id);
void			debug_print_redir_2(t_redirection *lst, int mode, int id, int counter);

// debug/debug_parse.c
void			debug_parse(t_main *config);
void			debug_print_line_block(t_block *line_block);

// debug/debug_print_cmd.c
void			debug_print_cmd(t_cmd *cmd, int id);
void			debug_print_cmd_2(t_cmd *cmd, int id);
void			debug_print_cmd_3(t_cmd *cmd, int id);

// minishell.c
char			**do_something_with_argv(char **argv);

// shell/exec/exec/exec_prepare.c
void			exec_prepare_between(t_context *context);
void			exec_prepare_entry(t_main *config);
void			exec_prepare_first(t_context *context);
void			exec_prepare_last(t_context *context);
void			exec_prepare_pipe(t_context *context);

// shell/exec/exec/execute.c
int				exec_entry(t_main *config);
void			exec_command(t_main *config);

// shell/exec/exec/prepare_cmds.c
size_t			init_cmds_count_args(t_list *tmp);
void			init_cmds(t_main *config);
void			init_get_cmd_paths(t_main *config);
void			prepare_cmds_1(t_main *config);
void			prepare_cmds_2(t_cmd *cmd, t_block **tmp, int prev_str);

// shell/exec/exec/prepare_redirection.c
void			prepare_in_double_file(t_redirection *double_in);
void			prepare_in_file(t_redirection *in_file, t_main *config);
void			prepare_out_double_file(t_redirection *double_out, t_main *config);
void			prepare_out_file(t_redirection *out, t_main *config);
void			prepare_redirection(t_main *config);

// shell/exec/exec/prepare_redirection_ng.c
void			prepare_in_file_ng(t_main *config);
void			prepare_out_file_ng(t_main *config);

// shell/exec/exec_engine.c
void			exec_engine(t_main *config);

// shell/loop.c
int				is_command_empty(t_main *config);
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

// utils/builtins/env_export_utils_1.c
t_lst_env		*env_to_lst(char **env);
void			export_var_to_env(t_lst_env **envlst, char *var);
void			index_env_lst(t_lst_env **envlst);
void			index_env_lst2(t_lst_env *lst, t_lst_env **tmp, t_lst_env **tmp2, int *i);

// utils/builtins/env_export_utils_2.c
int				ft_strcmp_env(char *s1, char *s2);
t_lst_env		*ft_lstadd_back_env(t_lst_env **lst, t_lst_env *new);
t_lst_env		*ft_lstnew_env(void *env);

// utils/exec/print_error.c
int				print_error_file(t_cmd *cmd);
int				print_error_infile(t_redirection *tmp);
int				print_error_outfile(t_redirection *tmp);
void			print_error(t_context *context);

// utils/exec/utils.c
void			close_all_pipes(t_context *config);
void			wait_for_all(t_context *config);

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
char			*get_path_from_env(t_lst_env *env);

// utils/get_prompt.c
char			*get_base_prompt(t_main *config);
char			*get_hostname(void);
void			get_base_prompt_assemble(t_main *config, t_list *prompt);

// utils/parsing/convert_list.c
t_block			*convert_list(t_list *input);

/* ########################################################################## */

#endif
