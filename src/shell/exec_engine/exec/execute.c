/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 08:02:07 by brda-sil          #+#    #+#             */
/*   Updated: 2022/09/21 06:26:28 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	execve_ng(t_cmd *cmd)
{
	int		error_code;

	error_code = 0;
	if (!cmd->path)
		error_code = 127;
	else if (access(cmd->path, X_OK) != 0)
		error_code = 126;
	else
		execve(cmd->path, cmd->command, FT_NULL);
	return (error_code);
}

int	exec_command(t_main *config, int is_last)
{
	t_context	*context;
	t_cmd		*cmd;
	int			error_code;

	context = config->context;
	cmd = context->cmd[config->context->cmd_id];
	exec_prepare_entry(config);
	close_all_pipes(config->context);
	if (cmd->builtin == NONE)
		error_code = execve_ng(cmd);
	else
		error_code = exec_builtin(cmd);
	if (is_last)
	{
		free_config_entry(config);
		exit (error_code);
	}
	return (error_code);
}

int	is_last(t_context *context)
{
	return (context->cmd_nb == 1 && context->fork_last);
}

void	exec_command_child(t_main *config, int islast)
{
	t_cmd	*cmd;

	cmd = config->context->cmd[config->context->cmd_id];
	cmd->return_value = exec_command(config, islast);
	if (islast)
	{
		if (cmd->builtin == CD)
			if (!cmd->return_value)
				builtin_cd_update_pwd(config);
	}
}

int	exec_entry(t_main *config)
{
	int		counter;
	t_bool	islast;

	counter = 0;
	while (counter < config->context->cmd_nb)
	{
		islast = is_last(config->context);
		if (islast)
			config->context->cmd[counter]->cmd_pid = fork();
		if (config->context->cmd[counter]->cmd_pid == 0)
			exec_command_child(config, islast);
		if (config->context->cmd_id == 0)
			config->context->cmd_id++;
		else
		{
			config->context->cmd_id++;
			config->context->pipe_id++;
		}
		counter++;
	}
	close_all_pipes(config->context);
	wait_for_all(config->context);
	print_error(config->context);
	return (config->context->cmd[config->context->cmd_nb - 1]->return_value);
}
