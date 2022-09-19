/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_prepare.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 00:47:46 by brda-sil          #+#    #+#             */
/*   Updated: 2022/09/19 01:54:33 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_prepare_first(t_context *context)
{
	t_cmd	*cmd;

	cmd = context->cmd[context->cmd_id];
	if (!cmd->out_redir && (context->cmd_nb != 1))
		dup2(context->pipes[context->pipe_id][1], STDOUT_FILENO);
}

void	exec_prepare_between(t_context *context)
{
	t_cmd	*cmd;

	cmd = context->cmd[context->cmd_id];
	if (!cmd->in_redir)
		dup2(context->pipes[context->pipe_id][0], STDIN_FILENO);
	if (!cmd->out_redir)
		dup2(context->pipes[context->pipe_id + 1][1], STDOUT_FILENO);
}

void	exec_prepare_last(t_context *context)
{
	t_cmd	*cmd;

	cmd = context->cmd[context->cmd_id];
	if (!cmd->in_redir)
		dup2(context->pipes[context->pipe_id][0], STDIN_FILENO);
}

void	exec_prepare_pipe(t_context *context)
{
	if (context->cmd_id == 0)
		exec_prepare_first(context);
	else if (context->cmd_id == context->cmd_nb - 1)
		exec_prepare_last(context);
	else
		exec_prepare_between(context);
}

void	exec_prepare_entry(t_main *config)
{
	prepare_redirection(config);
	exec_prepare_pipe(config->context);
}
