/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 00:13:28 by brda-sil          #+#    #+#             */
/*   Updated: 2022/09/22 03:21:10 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_config_entry(t_main *config)
{
	free(config->prompt_base);
	config->prompt_base = FT_NULL;
	free(config->prompt);
	config->prompt = FT_NULL;
	if (config->context)
		free_exec_entry(config);
	if (config->env != FT_NULL)
		free_t_list_env(config->env);
	free(config->prompt);
	config->prompt = FT_NULL;
	rl_clear_history();
}
