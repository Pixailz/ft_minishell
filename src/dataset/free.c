/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 04:02:41 by brda-sil          #+#    #+#             */
/*   Updated: 2022/09/01 03:35:24 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_char_pointer_pointer(char **str)
{
	int	counter;

	counter = 0;
	while (str[counter])
	{
		free(str[counter]);
		str[counter] = NULL;
		counter++;
	}
	free(str);
	str = NULL;
}

void	free_config(t_main *config)
{
	free(config->prompt);
	config->prompt = NULL;
	free_char_pointer_pointer(config->env_path);
	if (config->line_buffer != NULL)
	{
		free(config->line_buffer);
		config->line_buffer = NULL;
	}
}

void	free_cmd(t_cmd *cmd)
{
	free(cmd->name);
	cmd->name = NULL;
	free(cmd->path);
	cmd->path = NULL;
	if (cmd->have_arg)
		free_char_pointer_pointer(cmd->arg);
	free(cmd);
	cmd = NULL;
}

void	free_entry(t_main *config)
{
	free_config(config);
	free_cmd(config->cmd);
}
