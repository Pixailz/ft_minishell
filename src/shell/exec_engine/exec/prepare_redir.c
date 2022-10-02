/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_redir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 01:20:03 by brda-sil          #+#    #+#             */
/*   Updated: 2022/09/30 19:51:57 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	prepare_in_file(t_redirection *in_file, t_main *config)
{
	in_file->file = open(in_file->content, O_RDONLY);
	if (in_file->file > -1)
		dup2(in_file->file, STDIN_FILENO);
	else
	{
		close_all_pipes(config->context);
		free_config_entry(config);
		exit(1);
	}
	close(in_file->file);
}

void	prepare_out_file(t_redirection *out, t_main *config)
{
	out->file = open(out->content, O_CREAT | O_RDWR | O_TRUNC, 0000644);
	if (out->file > -1)
		dup2(out->file, STDOUT_FILENO);
	else
	{
		close_all_pipes(config->context);
		free_config_entry(config);
		exit(1);
	}
	close(out->file);
}

void	prepare_out_double_file(t_redirection *double_out, t_main *config)
{
	double_out->file = open(double_out->content, \
							O_WRONLY | O_CREAT | O_APPEND, 0000644);
	if (double_out->file > -1)
		dup2(double_out->file, STDOUT_FILENO);
	else
	{
		close_all_pipes(config->context);
		free_config_entry(config);
		exit(1);
	}
	close(double_out->file);
}

void	prepare_redirection(t_main *config)
{
	t_cmd	*cmd;

	cmd = config->context->cmd[config->context->cmd_id];
	if (cmd->in_redir)
		prepare_in_double_in_ng(config);
	if (cmd->out_redir)
		prepare_out_file_ng(config);
	if (cmd->in_redir)
	{
		prepare_in_file_ng(config);
		post_prepare_in_file(config);
	}
}
