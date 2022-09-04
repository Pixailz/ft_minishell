/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_engine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 05:56:03 by brda-sil          #+#    #+#             */
/*   Updated: 2022/09/04 03:51:36 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	do_command_begin(t_cmd *cmd)
{
}

void	wait_for_all_command(t_main *config)
{

}

int	exec_engine(t_main *config)
{
	config->cmd->pid = fork();
	if (config->cmd->pid == 0)
		do_command(config->cmd);
	wait_for_all_command(config);
}
