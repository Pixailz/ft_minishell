/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 05:20:53 by brda-sil          #+#    #+#             */
/*   Updated: 2022/08/29 21:38:23 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	debug_initial_prompt(char *prompt)
{
	ft_printf_fd(LOG_FD, "%s initial prompt\t\t[%s]\n", GREEN_PLUS, prompt);
}

void	debug_line_buffer(char *line)
{
	static int	id = 1;

	ft_printf_fd(LOG_FD, "%s line_buffer(%d)\t\t[%s]\n", GREEN_PLUS, id++, line);
}

int	debug_catched_signal(int sig)
{
	if (sig == -1)
	{
		ft_printf_fd(LOG_FD, "%s catched\t\t\tEOF\n", ORANGE_STAR);
		ft_printf_fd(LOG_FD, "   %s exiting\t\t\t0\n", GREEN_PLUS);
		return (1);
	}
	else if (sig == SIGINT)
		ft_printf_fd(LOG_FD, "%s catched\t\t\tSIGINT(2)\n", ORANGE_STAR);
	else if (sig == SIGQUIT)
		ft_printf_fd(LOG_FD, "%s catched\t\t\tSIGQUIT(3)\n", ORANGE_STAR);
	return (0);
}

void	debug_init_cmd(t_main *config)
{
	ft_printf_fd(LOG_FD, "%s nb_quote\t\t\t%d\n", GREEN_PLUS, \
														config->cmd->nb_quote);
	ft_printf_fd(LOG_FD, "%s nb_dquote\t\t\t%d\n", GREEN_PLUS, \
														config->cmd->nb_dquote);
}

void	debug_parse_splited(t_main *config)
{
	int	pos;

	ft_printf_fd(LOG_FD, "%s cmd->name\t\t\t%s\n", GREEN_PLUS, \
														config->cmd->name);
	if (config->cmd->have_arg)
	{
		pos = 0;
		ft_printf_fd(LOG_FD, "%s cmd->have_arg\t\tTrue\n", GREEN_PLUS);
		while (config->cmd->arg[pos])
		{
			ft_printf_fd(LOG_FD, "   %s cmd->arg[%d]\t\t[%s]\n", GREEN_PLUS, pos, \
														config->cmd->arg[pos]);
			pos++;
		}
	}
	else
		ft_printf_fd(LOG_FD, "%s cmd->have_arg\t\tFalse\n", GREEN_PLUS);
}
