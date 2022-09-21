/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 22:02:54 by brda-sil          #+#    #+#             */
/*   Updated: 2022/09/20 23:53:01 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	debug_print_cmd_2(t_cmd *cmd)
{
	int	counter;
	int	is_arg;

	counter = 0;
	is_arg = 0;
	ft_printf_fd(LOG_FD, "    %s cmd->path [%s]\n", ORANGE_STAR, cmd->path);
	while (cmd->command[counter])
	{
		if (is_arg)
			ft_printf_fd(LOG_FD, "    %s cmd->command[%d] (args)[%s]\n",
				ORANGE_STAR, counter, cmd->command[counter]);
		else
			ft_printf_fd(LOG_FD, "    %s cmd->command[%d] (base)[%s]\n", \
				ORANGE_STAR, counter, cmd->command[counter]);
		counter++;
		is_arg++;
	}
}

void	debug_print_cmd(t_cmd *cmd)
{
	if (cmd->in_redir)
		debug_print_redir_1(cmd->in_redir, 0);
	if (cmd->out_redir)
		debug_print_redir_1(cmd->out_redir, 1);
	debug_print_cmd_2(cmd);
	debug_builtin(cmd);
}
