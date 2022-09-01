/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 23:56:44 by brda-sil          #+#    #+#             */
/*   Updated: 2022/09/01 04:08:12 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/* ########################################################################## */
/* INCLUDE */
/* ####### */

# include "libft.h"

/*
SIGINT
*/
# include <signal.h>
/*
readline
*/
# include <stdio.h>
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

typedef struct s_cmd
{
	char	*name;
	char	*path;
	int		have_arg;
	char	**arg;
	int		nb_quote;
	int		nb_dquote;
}			t_cmd;

typedef struct s_main
{
	char	*prompt;
	char	**env_path;
	char	*line_buffer;
	char	**line_splited;
	t_cmd	*cmd;
}			t_main;

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

// builtins/export.c
int			ft_strcmp_env(char *s1, char *s2);
t_lst_env	*ft_lstadd_back_env(t_lst_env **lst, t_lst_env *new);
t_lst_env	*env_to_lst(char **env);
void		index_env_lst(t_lst_env **envlst);
void		export_var_to_env(t_lst_env **envlst, char *var);
void		print_env(t_lst_env *envlst);
void		print_export(t_lst_env *envlst);

// dataset/free.c
void		free_char_pointer_pointer(char **str);
void		free_cmd(t_cmd *cmd);
void		free_config(t_main *config);
void		free_entry(t_main *config);

// dataset/init.c
char		*init_get_prompt(void);
int			init_config(t_main *config, char **envp);
int			init_entry(t_main *config, char **envp);
int			init_signal(void);

// debug/debug_1.c
int			debug_catched_signal(int sig);
void		debug_init(t_main *config);
void		debug_init_cmd(t_main *config);
void		debug_line_buffer(char *line);
void		debug_splited_line(t_main *config);

// debug/debug_2.c
void		debug_parse_arg(t_cmd *cmd);

// minishell.c
char		**do_something_with_argv(char **argv);

// shell/exec_engine.c
int			exec_engine(t_main *config);

// shell/loop.c
int			main_loop(t_main *config);

// shell/parse_cmd.c
int			parse_cmd(t_main *config);
void		init_cmd(t_main *config);
void		parse_arg(t_main *config);
void		parse_splited(t_main *config);

// shell/signal_handler.c
void		handle_sig_int(void);
void		handle_sig_quit(void);
void		signal_handler(int signal_code);

// utils/ft_better_split.c
t_list		*ft_better_split(char *s);

// utils/ft_splitb.c
char		**ft_splitb(char *s, char delim, char *encl);
char		**ft_splitb_get_words(char *s, char delim, char *encl, int tab_size);
int			ft_splitb_get_size(char *str, char delim, char *encl);
int			ft_splitb_get_word(char **str, char delim, char *encl);

// utils/get_path.c
char		**get_path(char **env);
char		*get_cmd_path(char *name, char **path);

/* ########################################################################## */

#endif
