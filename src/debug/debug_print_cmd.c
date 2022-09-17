/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_print_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 22:02:54 by brda-sil          #+#    #+#             */
/*   Updated: 2022/09/17 22:16:36 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	debug_print_cmd_2(t_cmd *cmd, int id)
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
			ft_printf_fd(LOG_FD, "cmd[%d]->tmp_command[%d] [BASE] [%s]\n", \
				id, counter, tmp->content);
			is_base = 0;
		}
		else
			ft_printf_fd(LOG_FD, "cmd[%d]->tmp_command[%d] [ARGS] [%s]\n", \
				id, counter, tmp->content);
		tmp = tmp->next;
		counter++;
	}
}

void	debug_print_cmd_3(t_cmd *cmd, int id)
{
	int	counter;

	counter = 0;
	ft_printf_fd(LOG_FD, "cmd[%d]->path [%s]\n", id, cmd->path);
	while (cmd->command[counter])
	{
		ft_printf_fd(LOG_FD, "cmd[%d]->command[%d] [%s]\n", id, counter, \
			cmd->command[counter]);
		counter++;
	}
}

void	debug_print_cmd(t_cmd *cmd, int id)
{
	if (!cmd->in_redir)
		ft_printf_fd(LOG_FD, "cmd[%d]->in_redir [NULL]\n", id);
	else
		debug_print_redir_1(cmd->in_redir, 0, id);
	if (!cmd->out_redir)
		ft_printf_fd(LOG_FD, "cmd[%d]->out_redir [NULL]\n", id);
	else
		debug_print_redir_1(cmd->out_redir, 1, id);
	debug_print_cmd_2(cmd, id);
	debug_print_cmd_3(cmd, id);
}
