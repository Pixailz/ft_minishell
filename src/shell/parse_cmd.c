/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 05:54:34 by brda-sil          #+#    #+#             */
/*   Updated: 2022/09/01 04:08:43 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_cmd(t_main *config)
{
	config->cmd = (t_cmd *)malloc(sizeof(t_cmd));
	config->cmd->have_arg = 0;
	config->cmd->nb_quote = ft_strcchr(config->line_buffer, '\'');
	config->cmd->nb_dquote = ft_strcchr(config->line_buffer, '"');
	debug_init_cmd(config);
}

void	parse_arg(t_main *config)
{
	int	counter;

	config->cmd->have_arg = 1;
	counter = 1;
	while (config->line_splited[counter])
		counter++;
	config->cmd->arg = (char **)malloc(sizeof(char *) * (counter + 1));
	counter = 0;
	while (config->line_splited[counter + 1])
	{
		config->cmd->arg[counter] = \
								ft_strdup(config->line_splited[counter + 1]);
		counter++;
	}
	config->cmd->arg[counter] = NULL;
}

void	parse_splited(t_main *config)
{
	debug_splited_line(config);
	config->cmd->name = ft_strdup(config->line_splited[0]);
	config->cmd->path = get_cmd_path(config->cmd->name, config->env_path);
	if (!config->cmd->path)
		ft_printf_fd(LOG_FD, "   %s [%s] command not found.\n", RED_MINUS, \
															config->cmd->name);
	else
	{
		if (config->line_splited[1])
			parse_arg(config);
		else
			config->cmd->arg = NULL;
	}
	debug_parse_arg(config->cmd);
}

int	parse_cmd(t_main *config)
{
	init_cmd(config);
	config->line_splited = ft_splitb(config->line_buffer, ' ', "\"'");
	parse_splited(config);
	free(config->line_buffer);
	config->line_buffer = NULL;
	free_char_pointer_pointer(config->line_splited);
	return (0);
}
