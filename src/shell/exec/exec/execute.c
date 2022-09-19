/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 08:02:07 by brda-sil          #+#    #+#             */
/*   Updated: 2022/09/19 06:12:11 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_command(t_main *config)
{
	t_cmd	*cmd;
	int		return_code;

	cmd = config->context->cmd[config->context->cmd_id];
	exec_prepare_entry(config);
	close_all_pipes(config->context);
	if (!cmd->path)
		return_code = 127;
	else if (access(cmd->path, X_OK) != 0)
		return_code = 126;
	else
		execve(cmd->path, cmd->command, FT_NULL);
	free_config_entry(config);
	exit (return_code);
}

int	exec_entry(t_main *config)
{
	int	counter;

	counter = 0;
	while (counter < config->context->cmd_nb)
	{
		config->context->cmd[counter]->cmd_pid = fork();
		if (config->context->cmd[counter]->cmd_pid == 0)
			exec_command(config);
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
