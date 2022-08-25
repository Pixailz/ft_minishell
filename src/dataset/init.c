/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 03:17:16 by brda-sil          #+#    #+#             */
/*   Updated: 2022/08/25 06:30:12 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	init_signal(void)
{
	signal(SIGINT, signal_handler);
	signal(SIGQUIT, SIG_IGN);
	return (0);
}

char	*init_get_prompt(void)
{
	return (ft_strdup("minishell@hostname:~/Documents$ "));
}

int	init_config(t_main *config)
{
	config->prompt = init_get_prompt();
	debug_initial_prompt(config->prompt);
	config->line_buffer = NULL;
	return (0);
}

int	init_entry(t_main *config)
{
	init_config(config);
	init_signal();
	return (0);
}
