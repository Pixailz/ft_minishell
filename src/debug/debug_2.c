/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 01:32:17 by brda-sil          #+#    #+#             */
/*   Updated: 2022/09/04 03:35:12 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	debug_parse_arg(t_cmd *cmd)
{
	int	counter;

	ft_printf_fd(LOG_FD, "   %s cmd->name\t\t\t[%s]\n", GREEN_PLUS, cmd->name);
	if (cmd->path)
		ft_printf_fd(LOG_FD, "   %s cmd->path\t\t\t[%s]\n", GREEN_PLUS, \
																	cmd->path);
	if (cmd->have_arg)
	{
		counter = 0;
		ft_printf_fd(LOG_FD, "   %s cmd->have_arg\t\tTrue\n", GREEN_PLUS);
		while (cmd->arg[counter])
		{
			ft_printf_fd(LOG_FD, "   %s cmd->arg[%d]\t\t\t[%s]\n", GREEN_PLUS, \
													counter, cmd->arg[counter]);
			counter++;
		}
	}
	else
		ft_printf_fd(LOG_FD, "   %s cmd->have_arg\t\tFalse\n", GREEN_PLUS);
}
