/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 03:52:50 by brda-sil          #+#    #+#             */
/*   Updated: 2022/08/25 06:27:38 by brda-sil         ###   ########.fr       */
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
			free_entry(config);
			exit(debug_catched_signal(-1));
		}
		else
		{
			debug_line_buffer(config->line_buffer);
			parse_cmd(config);
			exec_engine(config);
			free(config->line_buffer);
		}
	}
	return (0);
}
