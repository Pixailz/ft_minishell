/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 23:56:44 by brda-sil          #+#    #+#             */
/*   Updated: 2022/08/25 06:26:06 by brda-sil         ###   ########.fr       */
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

typedef struct s_main
{
	char	*prompt;
	char	*line_buffer;
}				t_main;

/* ########################################################################## */

/* ########################################################################## */
/* FILES */
/* ##### */

// dataset/free.c
void	free_config(t_main *config);
void	free_entry(t_main *config);

// dataset/init.c
char	*init_get_prompt(void);
int		init_config(t_main *config);
int		init_entry(t_main *config);
int		init_signal(void);

// debug/debug_print.c
int		debug_catched_signal(int sig);
void	debug_initial_prompt(char *prompt);
void	debug_line_buffer(char *line);

// minishell.c
int		main(int argc, char **argv);

// shell/exec_engine.c
int		exec_engine(t_main *config);

// shell/loop.c
int		main_loop(t_main *config);

// shell/parse_cmd.c
int		parse_cmd(t_main *config);

// shell/signal_handler.c
void	arrange_prompt_sigint(void);
void	signal_handler(int signal_code);

/* ########################################################################## */

#endif
