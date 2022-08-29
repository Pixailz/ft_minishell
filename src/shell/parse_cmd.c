/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 05:54:34 by brda-sil          #+#    #+#             */
/*   Updated: 2022/08/26 00:00:15 by brda-sil         ###   ########.fr       */
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
	char	*argv;

	argv = ft_memnchr(config->line_buffer, ' ', ft_strlen(config->line_buffer));
	config->cmd->arg = ft_split(argv, ' ');
	config->cmd->have_arg = 1;
}

void	parse_splited(t_main *config)
{
	config->cmd->name = ft_strdup(config->line_splited[0]);
	if (config->line_splited[1])
		parse_arg(config);
	debug_parse_splited(config);
}

int	parse_cmd(t_main *config)
{
	init_cmd(config);
	config->line_splited = ft_split(config->line_buffer, ' ');
	parse_splited(config);
	free(config->line_buffer);
	config->line_buffer = NULL;
	return (0);
}
