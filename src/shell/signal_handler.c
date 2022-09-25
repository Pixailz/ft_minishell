/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 03:48:41 by brda-sil          #+#    #+#             */
/*   Updated: 2022/09/26 01:08:02 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_interrupt;

// void	ioctl_handler(void)
// {
// 	struct termios	tmp;
// 	struct winsize	win;

// 	ioctl(0, TIOCGWINSZ, &win);
// 	ioctl(0, TIOCSWINSZ, &win);
// 	ioctl(0, TCGETS, &tmp);
// 	ioctl(0, TCSETSW, &tmp);
// 	ioctl(0, TCXONC, TCOON);
// 	ioctl(255, TIOCSPGRP, &tmp);
// }

void	handle_sig_int(void)
{
	ft_printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	// ioctl_handler();
	g_interrupt = 1;
}

void	handle_sig_quit(void)
{
	ft_printf("\b\b  \b\b");
	rl_redisplay();
}

void	signal_handler(int signal_code)
{
	if (signal_code == SIGINT)
		handle_sig_int();
	if (signal_code == SIGQUIT)
		handle_sig_quit();
	debug_signal(signal_code);
}
