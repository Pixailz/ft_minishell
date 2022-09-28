/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 03:48:41 by brda-sil          #+#    #+#             */
/*   Updated: 2022/09/28 17:40:29 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_interrupt;

void	handle_sig_int(void)
{
	ft_printf("\n");
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
	g_interrupt = 1;
}

void	handle_sig_int_here_doc(void)
{
	close(0);
	g_interrupt = 3;
}

void	signal_handler_forked(int signal_code)
{
	if (signal_code == SIGINT)
		ft_printf("\n");
}

void	signal_handler(int signal_code)
{
	if (signal_code == SIGINT)
		handle_sig_int();
}

void	signal_handler_here_doc(int signal_code)
{
	if (signal_code == SIGINT)
		handle_sig_int_here_doc();
}
