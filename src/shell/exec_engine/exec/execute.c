/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 08:02:07 by brda-sil          #+#    #+#             */
/*   Updated: 2022/09/29 19:05:39 by brda-sil         ###   ########.fr       */
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

int	exec_command(t_main *config)
{
	t_context	*context;
	t_cmd		*cmd;
	int			error_code;

	context = config->context;
	cmd = context->cmd[config->context->cmd_id];
	exec_prepare_entry(config);
	close_all_pipes(config->context);
	get_error_interrupt(config);
	if (cmd->builtin == NOT_BUILTIN)
		error_code = execve_ng(cmd);
	else if (cmd->builtin != NONE)
		error_code = exec_builtin(cmd, config);
	if (config->context->fork_first)
	{
		free_config_entry(config);
		exit (error_code);
	}
	return (error_code);
}

int	is_last(t_context *context)
{
	return (context->cmd_nb != 1 && context->fork_first);
}

void	exec_command_child(t_main *config)
{
	t_cmd	*cmd;

	cmd = config->context->cmd[config->context->cmd_id];
	cmd->return_value = exec_command(config);
	if (!config->context->fork_first)
	{
		if (cmd->builtin == CD)
			if (!cmd->return_value)
				builtin_cd_update_pwd(config);
		if (cmd->builtin == EXIT)
			builtin_exit_post_exec(cmd, config);
	}
}

int	exec_entry(t_main *config)
{
	int			counter;
	t_context	*context;

	context = config->context;
	counter = 0;
	while (counter < config->context->cmd_nb)
	{
		if (context->cmd_nb != 1 || context->fork_first)
			context->cmd[counter]->cmd_pid = fork();
		if (context->cmd[counter]->cmd_pid == 0)
			exec_command_child(config);
		if (context->cmd_id == 0)
			context->cmd_id++;
		else
		{
			context->cmd_id++;
			context->pipe_id++;
		}
		counter++;
	}
	close_all_pipes(context);
	wait_for_all(context);
	print_error(context);
	return (context->cmd[context->cmd_nb - 1]->return_value);
}
