/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 03:52:50 by brda-sil          #+#    #+#             */
/*   Updated: 2022/09/01 02:41:55 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main_loop(t_main *config)
{
	int	tmp;

	while (VRAI)
	{
		config->line_buffer = readline(config->prompt);
		if (config->line_buffer == NULL)
		{
			ft_printf("\n");
			free_entry(config);
			exit(debug_catched_signal(-1));
		}
		else
		{
			debug_line_buffer(config->line_buffer);
			parse_cmd(config);
			tmp = ft_strncmp(config->cmd->name, "exit", 4);
			if (!tmp)
				break ;
			exec_engine(config);
			free_cmd(config->cmd);
		}
	}
	return (0);
}
