/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 05:20:53 by brda-sil          #+#    #+#             */
/*   Updated: 2022/08/25 06:27:32 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	debug_initial_prompt(char *prompt)
{
	ft_printf_fd(LOG_FD, "%s initial prompt:\t[%s]\n", GREEN_PLUS, prompt);
}

void	debug_line_buffer(char *line)
{
	static int	id = 1;

	ft_printf_fd(LOG_FD, "%s line_buffer(%d):\t[%s]\n", GREEN_PLUS, id++, line);
}

int	debug_catched_signal(int sig)
{
	if (sig == -1)
	{
		ft_printf_fd(LOG_FD, "%s catched:\t\tEOF\n", ORANGE_STAR);
		ft_printf_fd(LOG_FD, "   %s exiting:\t\t0\n", GREEN_PLUS);
		return (1);
	}
	else if (sig == SIGINT)
		ft_printf_fd(LOG_FD, "%s catched:\t\tSIGINT(2)\n", ORANGE_STAR);
	else if (sig == SIGQUIT)
		ft_printf_fd(LOG_FD, "%s catched:\t\tSIGQUIT(3)\n", ORANGE_STAR);
	return (0);
}
