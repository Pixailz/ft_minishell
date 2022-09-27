/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 03:52:50 by brda-sil          #+#    #+#             */
/*   Updated: 2022/09/25 21:32:04 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_interrupt = 0;

int	is_command_empty(t_main *config)
{
	char	*ptr;

	ptr = config->line_buffer;
	while (ft_isspace(*ptr))
		ptr++;
	return (*ptr == '\0');
}

void	exit_ctrl_d(t_main *config)
{
	if (exit_check_shlvl(config))
	{
		ft_printf("\n");
		free_config_entry(config);
		exit(config->last_return_value);
	}
}

void	handle_interrupt(t_main *config)
{
	config->interrupt = 0;
	if (g_interrupt == 1)
	{
		config->interrupt = 1;
		config->last_return_value = 130;
		g_interrupt = 0;
	}
}

int	main_loop(t_main *config)
{
	while (VRAI)
	{
		config->line_buffer = readline(config->prompt);
		handle_interrupt(config);
		ft_printf("%s", C_RESET);
		if (config->line_buffer != FT_NULL && config->line_buffer[0] != ' ')
			add_history(config->line_buffer);
		if (config->line_buffer == FT_NULL)
			exit_ctrl_d(config);
		else
		{
			if (is_command_empty(config))
				continue ;
			parse_cmd(config);
			exec_engine(config);
			get_prompt(config);
		}
	}
	return (0);
}
