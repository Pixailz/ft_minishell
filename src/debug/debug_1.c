/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 05:20:53 by brda-sil          #+#    #+#             */
/*   Updated: 2022/09/04 03:35:34 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	debug_init(t_main *config)
{
	int	counter;

	ft_printf_fd(LOG_FD, "%s initial prompt\t\t\t[%s]\n", GREEN_PLUS, \
																config->prompt);
	counter = 0;
	while (config->env_path[counter])
	{
		ft_printf_fd(LOG_FD, "   %s path[%d]\t\t\t\t[%s]\n", GREEN_PLUS, \
											counter, config->env_path[counter]);
		counter++;
	}
}

void	debug_line_buffer(char *line)
{
	static int	id = 1;

	ft_printf_fd(LOG_FD, "%s line_buffer(%d)\t\t\t[%s]\n", GREEN_PLUS, id++, line);
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
	ft_printf_fd(LOG_FD, "   %s nb_quote\t\t\t\t%d\n", GREEN_PLUS, \
														config->cmd->nb_quote);
	ft_printf_fd(LOG_FD, "   %s nb_dquote\t\t\t%d\n", GREEN_PLUS, \
														config->cmd->nb_dquote);
}

void	debug_splited_line(t_main *config)
{
	int	counter;

	counter = 0;
	while (config->line_splited[counter])
	{
		ft_printf_fd(LOG_FD, "      %s line_splitted[%d]\t[%s]\n", GREEN_PLUS, \
							counter, config->line_splited[counter]);
		counter++;
	}
}
