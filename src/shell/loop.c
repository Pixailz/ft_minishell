/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 03:52:50 by brda-sil          #+#    #+#             */
/*   Updated: 2022/09/20 07:56:08 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_command_empty(t_main *config)
{
	char	*ptr;

	ptr = config->line_buffer;
	while (ft_isspace(*ptr))
		ptr++;
	return (*ptr == '\0');
}

int	main_loop(t_main *config)
{
	while (VRAI)
	{
		config->line_buffer = readline(config->prompt);
		ft_printf("%s", C_RESET);
		if (config->line_buffer == FT_NULL)
		{
			ft_printf("\n");
			free_config_entry(config);
			exit(debug_signal(EOF));
		}
		else
		{
			if (is_command_empty(config))
				continue ;
			if (config->line_buffer[0] != ' ')
				add_history(config->line_buffer);
			parse_cmd(config);
			debug_parse(config);
			exec_engine(config);

			get_prompt(config);
		}
	}
	return (0);
}
