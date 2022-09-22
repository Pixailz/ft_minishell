/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 21:50:34 by brda-sil          #+#    #+#             */
/*   Updated: 2022/09/22 06:53:36 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	debug_params(t_cmd *cmd)
{
	if (cmd->builtin == ECHOO)
	{
		ft_printf_fd(LOG_FD, "      %s have args? [True]\n", GREEN_PLUS);
		if (is_params(cmd->command[1], "n"))
			ft_printf_fd(LOG_FD, "      %s is params? [True]\n", GREEN_PLUS);
		else
			ft_printf_fd(LOG_FD, "      %s is params? [False]\n", RED_MINUS);
	}
}

void	debug_print_builtin(int builtin)
{
	if (builtin == CD)
		ft_printf_fd(LOG_FD, "    %s cd:\n", BLUE_STAR);
	else if (builtin == PWD)
		ft_printf_fd(LOG_FD, "    %s pwd:\n", BLUE_STAR);
	else if (builtin == ECHOO)
		ft_printf_fd(LOG_FD, "    %s echo:\n", BLUE_STAR);
	else if (builtin == EXPORT)
		ft_printf_fd(LOG_FD, "    %s export:\n", BLUE_STAR);
	else if (builtin == ENV)
		ft_printf_fd(LOG_FD, "    %s env:\n", BLUE_STAR);
	else
		ft_printf_fd(LOG_FD, "    %s not a builtins\n", RED_MINUS);
}

void	debug_builtin(t_cmd *cmd)
{
	debug_print_builtin(cmd->builtin);
	if (have_args(cmd))
		debug_params(cmd);
	else
		ft_printf_fd(LOG_FD, "      %s have args? [False]\n", RED_MINUS);
}
