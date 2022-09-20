/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_signal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 01:13:26 by brda-sil          #+#    #+#             */
/*   Updated: 2022/09/20 01:17:45 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	debug_signal(int signal_code)
{
	ft_printf_fd(LOG_FD, "%s signal_handler:\n", BLUE_STAR);
	ft_printf_fd(LOG_FD, "   %s signal_catched [", GREEN_PLUS);
	if (signal_code == -1)
		ft_printf_fd(LOG_FD, "EOF");
	else if (signal_code == SIGINT)
		ft_printf_fd(LOG_FD, "SIGINT");
	else if (signal_code == SIGQUIT)
		ft_printf_fd(LOG_FD, "SIGQUIT");
	ft_printf_fd(LOG_FD, "(%d)]\n", signal_code);
	return (signal_code);
}
