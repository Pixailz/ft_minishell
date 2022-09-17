/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_prepare.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 00:47:46 by brda-sil          #+#    #+#             */
/*   Updated: 2022/09/17 05:23:17 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_prepare_first(t_context *config)
{
	t_cmd	*cmd;

	cmd = config->cmd[config->cmd_id];
	if (!cmd->out_redir && !cmd->double_out_redir && (config->cmd_nb != 1))
		dup2(config->pipes[config->pipe_id][1], STDOUT_FILENO);
}

void	exec_prepare_between(t_context *config)
{
	t_cmd	*cmd;

	cmd = config->cmd[config->cmd_id];
	if (!cmd->in_redir && !cmd->double_in_redir)
		dup2(config->pipes[config->pipe_id][0], STDIN_FILENO);
	if (!cmd->out_redir && !cmd->double_out_redir)
		dup2(config->pipes[config->pipe_id + 1][1], STDOUT_FILENO);
}

void	exec_prepare_last(t_context *config)
{
	t_cmd	*cmd;

	cmd = config->cmd[config->cmd_id];
	if (!cmd->in_redir && !cmd->double_in_redir)
		dup2(config->pipes[config->pipe_id][0], STDIN_FILENO);
}

void	exec_prepare_pipe(t_context *config)
{
	if (config->cmd_id == 0)
		exec_prepare_first(config);
	else if (config->cmd_id == config->cmd_nb - 1)
		exec_prepare_last(config);
	else
		exec_prepare_between(config);
}

void	exec_prepare_entry(t_context *config)
{
	exec_prepare_redirection(config);
	exec_prepare_pipe(config);
}
