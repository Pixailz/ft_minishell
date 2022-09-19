/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 00:13:28 by brda-sil          #+#    #+#             */
/*   Updated: 2022/09/19 05:24:06 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_config_entry(t_main *config)
{
	free(config->prompt);
	config->prompt = FT_NULL;
	if (config->line_buffer)
	{
		free(config->line_buffer);
		config->line_buffer = FT_NULL;
	}
	if (config->context)
		free_exec_entry(config);
	free_t_list_env(config->env);
	free(config->prompt);
	config->prompt = FT_NULL;
}
