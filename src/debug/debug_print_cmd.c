/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_print_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 22:02:54 by brda-sil          #+#    #+#             */
/*   Updated: 2022/09/20 01:43:59 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	debug_print_cmd_2(t_cmd *cmd)
{
	t_list	*tmp;
	int		is_base;
	int		counter;

	tmp = cmd->tmp_command;
	is_base = 1;
	counter = 0;
	while (tmp)
	{
		if (is_base)
		{
			ft_printf_fd(LOG_FD, \
				"      %s cmd->tmp_command[%d] [BASE] [%s]\n", ORANGE_STAR, \
					counter, tmp->content);
			is_base = 0;
		}
		else
			ft_printf_fd(LOG_FD, \
				"      %s cmd->tmp_command[%d] [ARGS] [%s]\n", ORANGE_STAR, \
					counter, tmp->content);
		tmp = tmp->next;
		counter++;
	}
}

void	debug_print_cmd_3(t_cmd *cmd)
{
	int	counter;

	counter = 0;
	ft_printf_fd(LOG_FD, "      %s cmd->path [%s]\n", ORANGE_STAR, cmd->path);
	while (cmd->command[counter])
	{
		ft_printf_fd(LOG_FD, "      %s cmd->command[%d] [%s]\n", ORANGE_STAR, \
			counter, cmd->command[counter]);
		counter++;
	}
}

void	debug_print_cmd(t_cmd *cmd)
{
	if (cmd->in_redir)
		debug_print_redir_1(cmd->in_redir, 0);
	if (cmd->out_redir)
		debug_print_redir_1(cmd->out_redir, 1);
	debug_print_cmd_2(cmd);
	debug_print_cmd_3(cmd);
}
