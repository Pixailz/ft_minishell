/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_init_redirection.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 05:13:49 by brda-sil          #+#    #+#             */
/*   Updated: 2022/09/17 05:59:19 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	debug_print_redir(t_redirection *lst, char *type, int id)
{
	int	counter;

	counter = 0;
	while (lst)
	{
		ft_printf_fd(LOG_FD, "cmd[%d]->%s[%d] [%s]\n", id, \
			type, counter, lst->content);
		lst = lst->next;
		counter++;
	}
}

void	debug_print_cmd(t_cmd *cmd, int id)
{
	if (!cmd->in_redir)
		ft_printf_fd(LOG_FD, "cmd[%d]->in_redir [NULL]\n", id);
	else
		debug_print_redir(cmd->in_redir, "in_redir", id);
	if (!cmd->double_in_redir)
		ft_printf_fd(LOG_FD, "cmd[%d]->double_in_redir [NULL]\n", id);
	else
		debug_print_redir(cmd->double_in_redir, "double_in_redir", id);
	if (!cmd->out_redir)
		ft_printf_fd(LOG_FD, "cmd[%d]->out_redir [NULL]\n", id);
	else
		debug_print_redir(cmd->out_redir, "out_redir", id);
	if (!cmd->double_out_redir)
		ft_printf_fd(LOG_FD, "cmd[%d]->double_out_redir [NULL]\n", id);
	else
		debug_print_redir(cmd->double_out_redir, "double_out_redir", id);
}

void	debug_init_redirection(t_main *config)
{
	int	counter;

	counter = 0;
	while (counter < config->context->cmd_nb)
	{
		debug_print_cmd(config->context->cmd[counter], counter);
		counter++;
	}
}
