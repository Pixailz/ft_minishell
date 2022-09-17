/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 03:52:50 by brda-sil          #+#    #+#             */
/*   Updated: 2022/09/17 03:17:54 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main_loop(t_main *config)
{
	while (VRAI)
	{
		config->line_buffer = readline(config->prompt);
		if (config->line_buffer == NULL)
		{
			ft_printf("\n");
			free_entry(config);
			exit(-1);
		}
		else
		{
			if (!ft_strncmp(config->line_buffer, "exit", 4))
				break ;
			parse_cmd_entry(config);
			debug_parse(config);
			exec_engine(config);
		}
	}
	return (0);
}
