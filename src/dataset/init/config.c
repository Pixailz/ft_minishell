/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 00:19:08 by brda-sil          #+#    #+#             */
/*   Updated: 2022/09/20 01:58:46 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	init_config(t_main *config, char **envp)
{
	config->last_return_value = 0;
	config->env = env_to_lst(envp);
	// export_var_to_env(&config->env, "SHELL=minishell");
	config->prompt_base = get_base_prompt(config);
	debug_prompt_base(config);
	config->cwd = get_cwd();
	config->prompt = FT_NULL;
	get_prompt(config);
	config->line_buffer = FT_NULL;
	config->context = FT_NULL;
	return (0);
}

int	init_config_entry(t_main *config, char **envp)
{
	init_config(config, envp);
	init_signal();
	return (0);
}
