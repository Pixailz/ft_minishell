/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 23:56:44 by brda-sil          #+#    #+#             */
/*   Updated: 2022/08/24 21:29:58 by brda-sil         ###   ########.fr       */
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

/* ########################################################################## */

/* ########################################################################## */
/* STRUCT */
/* ###### */

/* ########################################################################## */

/* ########################################################################## */
/* FILES */
/* ##### */

// loop.c
int	main_loop(void);

// minishell.c
int	main(int argc, char **argv);

/* ########################################################################## */

#endif
