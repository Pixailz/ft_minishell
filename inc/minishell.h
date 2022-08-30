/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 23:56:44 by brda-sil          #+#    #+#             */
/*   Updated: 2022/08/26 00:14:44 by brda-sil         ###   ########.fr       */
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
	char	*line_buffer;
	char	**line_splited;
	t_cmd	*cmd;
}			t_main;

/* ########################################################################## */

/* ########################################################################## */
/* FILES */
/* ##### */

// dataset/free.c
void	free_cmd(t_main *config);
void	free_config(t_main *config);
void	free_entry(t_main *config);

// dataset/init.c
char	*init_get_prompt(void);
int		init_config(t_main *config);
int		init_entry(t_main *config);
int		init_signal(void);

// debug/debug_print.c
int		debug_catched_signal(int sig);
void	debug_init_cmd(t_main *config);
void	debug_initial_prompt(char *prompt);
void	debug_line_buffer(char *line);
void	debug_parse_splited(t_main *config);

// minishell.c
char	**do_something_with_argv(char **argv);
int		main(int argc, char **argv);

// shell/exec_engine.c
int		exec_engine(t_main *config);

// shell/loop.c
int		main_loop(t_main *config);

// shell/parse_cmd.c
int		parse_cmd(t_main *config);
void	init_cmd(t_main *config);
void	parse_arg(t_main *config);
void	parse_splited(t_main *config);

// shell/signal_handler.c
void	handle_sig_int(void);
void	handle_sig_quit(void);
void	signal_handler(int signal_code);

// utils/ft_better_split.c
t_list	*ft_better_split(char *s);
char	*ft_better_init_str(char *s, char c);

/* ########################################################################## */

#endif
