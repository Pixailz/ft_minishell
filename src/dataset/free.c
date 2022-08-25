/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 04:02:41 by brda-sil          #+#    #+#             */
/*   Updated: 2022/08/25 06:27:20 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_config(t_main *config)
{
	free(config->prompt);
	config->prompt = NULL;
	if (config->line_buffer != NULL)
	{
		free(config->line_buffer);
		config->line_buffer = NULL;
	}
}

void	free_entry(t_main *config)
{
	free_config(config);
}
