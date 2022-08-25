/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 04:02:41 by brda-sil          #+#    #+#             */
/*   Updated: 2022/08/26 00:01:05 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_config(t_main *config)
{
	free(config->prompt);
	config->prompt = NULL;
	if (config->line_buffer != NULL)
	{
		free(config->line_buffer);
		config->line_buffer = NULL;
	}
}

void	free_cmd(t_main *config)
{
	int	counter;

	free(config->cmd->name);
	config->cmd->name = NULL;
	counter = 0;
	while (config->cmd->arg[counter])
	{
		free(config->cmd->arg[counter]);
		config->cmd->arg[counter] = NULL;
		counter++;
	}
	free(config->cmd->arg);
	config->cmd->arg = NULL;
	free(config->cmd);
	config->cmd = NULL;
}

void	free_entry(t_main *config)
{
	free_config(config);
	free_cmd(config);
}
