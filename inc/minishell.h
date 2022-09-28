/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 23:56:44 by brda-sil          #+#    #+#             */
/*   Updated: 2022/09/28 03:28:28 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/* ########################################################################## */
/* INCLUDE */
/* ####### */

# include "libft.h"

# include <fcntl.h>
/* O_RDONLY
 */

# include <signal.h>
/* SIGINT
 */

# include <sys/wait.h>
/* waitpid()
 */

# include <sys/stat.h>
/* stat()
 */

# include <readline/readline.h>
/* readline()
 */

# include <readline/history.h>
/* add_history()
 */

# include <unistd.h>
/* chdir()
 */

# include <errno.h>
/* errno
 */

# include <sys/ioctl.h>
/* ioctl()
 * TCXONC
 */

# include <termios.h>
/* TCOON
 */

/* ########################################################################## */

/* ########################################################################## */
/* CONFIG */
/* ###### */

# ifndef DEBUG
#  define DEBUG				1
# endif

# define TMP_ST "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"
# define VRAI				42

# define LOG_FD				420

# define C_RED				"\001\033[31m\002"
# define C_GREEN			"\001\033[32m\002"
# define C_LIGHT_GREEN		"\001\033[38;5;112m\002"
# define C_YELLOW			"\001\033[33m\002"
# define C_ORANGE			"\001\033[38;5;208m\002"
# define C_BLUE				"\001\033[34m\002"
# define C_PURPLE			"\001\033[35m\002"
# define C_MAGENTA			"\001\033[36m\002"
# define C_WHITE			"\001\033[37m\002"
# define C_BLACK			"\001\033[30m\002"

# define B_RED				"\001\033[01;31m\002"
# define B_GREEN			"\001\033[01;32m\002"
# define B_LIGHT_GREEN		"\001\033[01;38;5;112m\002"
# define B_YELLOW			"\001\033[01;33m\002"
# define B_ORANGE			"\001\033[01;38;5;208m\002"
# define B_BLUE				"\001\033[01;34m\002"
# define B_PURPLE			"\001\033[01;35m\002"
# define B_MAGENTA			"\001\033[01;36m\002"
# define B_WHITE			"\001\033[01;37m\002"
# define B_BLACK			"\001\033[01;30m\002"

# define C_RESET			"\001\033[0m\002"

# define GREEN_PLUS			"\001\033[0m[\033[38;5;82m+\033[0m]\002"
# define RED_MINUS			"\001\033[0m[\033[38;5;196m-\033[0m]\002"
# define ORANGE_STAR		"\001\033[0m[\033[38;5;214m*\033[0m]\002"
# define BLUE_STAR			"\001\033[0m[\033[38;5;75m*\033[0m]\002"

// prompt_config :)
# define OLD_STYLE			0

# define C_PROMPT_ROOT		B_RED
# define C_PROMPT_BASE		B_ORANGE
# define C_PROMPT_PATH		B_BLUE
# define C_PROMPT_CMD		C_RESET

# define C_PROMPT_STATUS_1	B_LIGHT_GREEN
# define C_PROMPT_STATUS_2	B_ORANGE
# define C_PROMPT_STATUS_0	B_RED

/* ########################################################################## */

/* ########################################################################## */
/* STRUCT / ENUM / TYPEDEF */
/* ####################### */

// BOOOL
typedef enum e_bool
{
	False,
	True
}			t_bool;

typedef struct s_main
{
	int					last_return_value;
	int					interrupt;
	char				*prompt_base;
	char				*user;
	char				*home;
	char				*cwd;
	char				*prompt;
	char				*line_buffer;
	t_list				*line_splitted;
	struct s_block		*line_block;
	struct s_context	*context;
	struct s_lst_env	*env;
}			t_main;

// EXEC ENGINE PART

enum e_builtin_type
{
	NONE,
	NOT_BUILTIN,
	CD,
	PWD,
	ECHOO,
	EXPORT,
	ENV,
	UNSET,
	EXIT,
	MINISHELL
};

typedef struct s_cmd
{
	t_list					*tmp_command;
	char					*path;
	char					**command;
	pid_t					cmd_pid;
	struct s_redirection	*in_redir;
	struct s_redirection	*out_redir;
	int						return_value;
	int						builtin;
}							t_cmd;

typedef struct s_redirection
{
	char					*content;
	int						is_double;
	int						file;
	char					*file_name;
	struct s_redirection	*next;
}				t_redirection;

typedef struct s_context
{
	int		cmd_nb;
	int		cmd_id;
	int		pipe_id;
	int		default_in;
	int		default_out;
	t_bool	fork_first;
	int		**pipes;
	t_cmd	**cmd;
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

// builtins/cd.c
int				builtin_cd(t_cmd *cmd, t_main *config);
int				cd_get_error_code(t_cmd *cmd);
void			builtin_cd_update_pwd(t_main *config);

// builtins/echo.c
int				builtin_echo(t_cmd *cmd);
int				builtin_echo_have_params(t_cmd *cmd);

// builtins/env.c
int				builtin_env(t_lst_env *envlst);

// builtins/exit.c
int				builtin_exit(t_cmd *cmd, t_main *config);
int				exit_check_exit_code(char *exit_code);
int				exit_check_shlvl(t_main *config);
int				exit_get_exit_code(char *exit_code);
void			builtin_exit_post_exec(t_cmd *cmd, t_main *config);

// builtins/export.c
int				builtin_export(t_cmd *cmd, t_main *config);
int				print_export(t_lst_env *envlst);
int				print_export_failed(char *var);
void			export_var_to_env(t_lst_env **envlst, char *var);

// builtins/pwd.c
int				builtin_pwd(t_cmd *cmd);

// builtins/unset.c
int				builtin_unset(t_cmd *cmd, t_main *config);
void			unset(char *var, t_lst_env **env);
void			unset2(t_lst_env *tmp, t_lst_env **env, t_lst_env *first);

// builtins/utils/args.c
t_bool			have_args(t_cmd *cmd);
t_bool			have_multiple_args(t_cmd *cmd);

// builtins/utils/do_something_with_cmd.c
void			*do_something_with_cmd(t_cmd *cmd);

// builtins/utils/env.c
char			*get_env(char *key, t_lst_env *env);
void			set_env(char *key, char *value, t_lst_env **env);

// builtins/utils/env_export_utils_1.c
t_lst_env		*env_to_lst(char **env);
void			index_env_lst(t_lst_env *env);
void			unlink_key_value(char *var_env, char **key, char **value);

// builtins/utils/env_export_utils_2.c
int				ft_strcmp_env(char *s1, char *s2);
t_lst_env		*ft_lstadd_back_env(t_lst_env **lst, t_lst_env *new);
t_lst_env		*ft_lstnew_env(void *env);

// builtins/utils/get_cwd.c
char			*get_cwd(void);

// builtins/utils/is_good_var_env.c
int				is_good_var_env(char *str);
int				is_good_var_env_char(char c);
int				is_good_var_env_first(char c);

// builtins/utils/params.c
t_bool			have_params(char *options, t_cmd *cmd);
t_bool			is_params(const char *argv, const char *options);

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

// dataset/init/get_prompt.c
int				get_prompt_init(t_main *config);
void			get_prompt_init_cwd(t_main *config);

// dataset/init/redirection.c
t_redirection	*redir_new(char *content, int is_double);
void			init_redirection(t_main *config);
void			init_redirection_lst(t_redirection **lst, char *content, int is_double);
void			redir_addback(t_redirection **lst, t_redirection *new);

// debug/builtin.c
void			debug_builtin(t_cmd *cmd);
void			debug_builtin_echo(t_cmd *cmd);
void			debug_print_builtin(int builtin);

// debug/init_redirection.c
void			debug_init_redirection(t_main *config);
void			debug_print_redir_1(t_redirection *lst, int mode);
void			debug_print_redir_2(t_redirection *lst, int mode, int counter);

// debug/parse.c
void			debug_parse(t_main *config);

// debug/print.c
void			debug_print_entry(int type, void *ptr);
void			debug_print_post_exec(t_main *config);

// debug/print_bool.c

// debug/print_cmd.c
void			debug_print_cmd(t_cmd *cmd);
void			debug_print_cmd_2(t_cmd *cmd);

// debug/prompt.c
void			debug_prompt(t_main *config);
void			debug_prompt_base(t_main *config);

// debug/signal.c
int				debug_signal(int signal_code);

// minishell.c
char			**do_something_with_argv(char **argv);

// shell/exec_engine/exec/exec_builtin.c
int				exec_builtin(t_cmd *cmd, t_main *config);

// shell/exec_engine/exec/exec_minishell.c
int				exec_minishell(t_main *config);

// shell/exec_engine/exec/exec_prepare.c
void			exec_prepare_between(t_context *context);
void			exec_prepare_entry(t_main *config);
void			exec_prepare_first(t_context *context);
void			exec_prepare_last(t_context *context);
void			exec_prepare_pipe(t_context *context);

// shell/exec_engine/exec/execute.c
int				exec_command(t_main *config);
int				exec_entry(t_main *config);
int				execve_ng(t_cmd *cmd);
int				is_last(t_context *context);
void			exec_command_child(t_main *config);

// shell/exec_engine/exec/prepare_cmds.c
size_t			init_cmds_count_args(t_list *tmp);
void			init_cmds(t_main *config);
void			init_get_cmd_paths(t_main *config);
void			prepare_cmds_1(t_main *config);
void			prepare_cmds_2(t_cmd *cmd, t_block **tmp, int prev_str);

// shell/exec_engine/exec/prepare_redir.c
void			prepare_in_file(t_redirection *in_file, t_main *config);
void			prepare_out_double_file(t_redirection *double_out, t_main *config);
void			prepare_out_file(t_redirection *out, t_main *config);
void			prepare_redirection(t_main *config);

// shell/exec_engine/exec/prepare_redir_heredoc.c
char			*get_tmp_file(void);
void			forked_double_in(t_redirection *double_in, t_main *conf);
void			prepare_in_double_file(t_redirection *double_in, t_main *config);

// shell/exec_engine/exec/prepare_redir_ng.c
void			post_prepare_in_file(t_main *config, t_redirection *last);
void			prepare_in_file_ng(t_main *config);
void			prepare_out_file_ng(t_main *config);

// shell/exec_engine/exec_engine.c
void			exec_engine(t_main *config);

// shell/exec_engine/utils/builtins.c
int				get_builtin(t_cmd *cmd);
int				is_good_builin(char *from, char *to);
t_bool			get_fork_first(int type);
t_bool			is_minishell(char *cmd);
void			get_builtins(t_main *config);

// shell/exec_engine/utils/path.c
char			**get_path(char **env);
char			*get_cmd_path(char *name, char **path);

// shell/exec_engine/utils/print_error.c
int				print_error_file(t_cmd *cmd);
int				print_error_infile(t_redirection *tmp);
int				print_error_outfile(t_redirection *tmp);
void			print_error(t_context *context);
void			print_error_2(t_cmd *cmd);

// shell/exec_engine/utils/utils.c
void			close_all_pipes(t_context *context);
void			wait_for_all(t_context *context);

// shell/loop.c
int				is_command_empty(t_main *config);
int				main_loop(t_main *config);
void			exit_ctrl_d(t_main *config);
void			handle_interrupt(t_main *config);

// shell/parsing_cmd/get_block.c
t_block			*ft_lstadd_back_block(t_block **lst, t_block *new);
t_block			*ft_lstnew_block(void *content);
void			get_block(t_block *input);
void			join_all(t_block *input);
void			trim_quotes(t_block *input);

// shell/parsing_cmd/identify_pipe.c
int				is_in_forward(t_block *input);
int				is_out_forward(t_block *input);
int				is_pipe(t_block *input);
void			identify_redirection(t_block *input);

// shell/parsing_cmd/parse_entry.c
void			parse_cmd(t_main *config);

// shell/parsing_cmd/replace_dollar.c
char			*find_key(t_main *config, char **input, t_lst_env *env);
char			*find_key_2(int i, char **input, char **key, t_lst_env *env);
char			*replace_key(t_main *config, char *input, t_lst_env *env);
char			*replace_question_mark(t_main *config, char **input);
void			parse_replace_dollar(t_main *config, t_lst_env *env);

// shell/parsing_cmd/utils/convert_list.c
t_block			*convert_list(t_list *input);

// shell/prompt/get_base_prompt.c
char			*assemble_base_prompt(char *user, char **hostname);
char			*get_base_prompt(t_main *config);
char			*get_hostname(void);

// shell/prompt/get_prompt.c
char			*get_prompt_2(t_main *config, char *tmp_1);
char			*get_prompt_no_tilde(t_main *config);
char			*get_prompt_tilde(t_main *config);
void			get_prompt(t_main *config);

// shell/prompt/get_status_prompt.c
char			*get_status_prompt(t_main *config);
char			*get_status_prompt_array(t_main *config);
char			*get_status_prompt_assemble(int status_code, char **array);
int				get_status_prompt_color(t_main *config);

// shell/signal_handling/handler.c
void			handle_sig_int(void);
void			handle_sig_int_here_doc(void);
void			signal_handler(int signal_code);
void			signal_handler_forked(int signal_code);
void			signal_handler_here_doc(int signal_code);

// shell/signal_handling/signal.c
void			set_signal_base(void);
void			set_signal_forked(int mode);

// utils/ft_better_split.c
t_list			*ft_better_split(char *s);
void			manage_quotes(char **s, char c, t_list **input);
void			manage_strings(char **s, t_list **input);
void			manage_symbols(char **s, char c, t_list **input);

// utils/ft_better_strjoin.c
char			*ft_better_strjoin(char *s1, char *s2);

// utils/ft_isdir.c
int				ft_isdir(char *dir_name, int mode);

// utils/ft_isfile.c
int				ft_isfile(char *file_path, int mode);

// utils/ft_patoi.c
int				ft_is_good_int(t_int64 n, int neg);
int				ft_patoi(char *nstr, int *has_overflow);

// utils/ft_patoll.c
int				ft_is_good_long_long(t_int64 n, int neg);
t_int64			ft_patoll(char *nstr, int *has_overflow);

// utils/ft_randint.c
t_int64			ft_randint(int start, int end);

// utils/ft_splitb.c
char			**ft_splitb(char *s, char delim, char *encl);
char			**ft_splitb_get_words(char *s, char delim, char *encl, int tab_size);
int				ft_splitb_get_size(char *str, char delim, char *encl);
int				ft_splitb_get_word(char **str, char delim, char *encl);

// utils/ft_tmpfile.c
char			*ft_tmpfile(int in_tmp);

/* ########################################################################## */

#endif
