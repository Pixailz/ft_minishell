/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 08:02:07 by brda-sil          #+#    #+#             */
/*   Updated: 2022/09/11 07:21:47 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_command(t_context *config)
{
	t_cmd	*cmd;

	cmd = config->cmd[config->cmd_id];
	exec_prepare_entry(config);
	close_all_pipes(config);
	execve(cmd->path, cmd->command, NULL);
	free_exec_entry(config);
	exit (127);
}

int	exec_entry(t_context *config)
{
	int	counter;

	counter = 0;
	while (counter < config->cmd_nb)
	{
		config->cmd[counter]->cmd_pid = fork();
		if (config->cmd[counter]->cmd_pid == 0)
			exec_command(config);
		if (config->cmd_id == 0)
			config->cmd_id++;
		else
		{
			config->cmd_id++;
			config->pipe_id++;
		}
		counter++;
	}
	close_all_pipes(config);
	wait_for_all(config);
	print_command_not_found(config);
	return (config->cmd[config->cmd_nb - 1]->return_value);
}
