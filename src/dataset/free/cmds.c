/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 00:18:32 by brda-sil          #+#    #+#             */
/*   Updated: 2022/09/19 02:24:11 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_cmd(t_cmd *cmd)
{
	free_t_list(cmd->tmp_command);
	free(cmd->path);
	cmd->path = FT_NULL;
	free_char_pointer_pointer(cmd->command);
	if (!cmd->in_redir)
		free_t_redirection(cmd->in_redir);
	if (!cmd->out_redir)
		free_t_redirection(cmd->out_redir);
}

void	free_cmds(t_context *context)
{
	int	counter;

	counter = 0;
	ft_printf_fd(LOG_FD, "cmd_nb %d\n", context->cmd_nb);
	while (counter < context->cmd_nb)
	{
		ft_printf_fd(LOG_FD, "counter %d\n", counter);
		free_cmd(context->cmd[counter]);
		free(context->cmd);
		context->cmd = FT_NULL;
		counter++;
	}
}
