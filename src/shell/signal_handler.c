/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 03:48:41 by brda-sil          #+#    #+#             */
/*   Updated: 2022/09/25 21:24:30 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_interrupt;

void	handle_sig_int(void)
{
	ft_printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
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
