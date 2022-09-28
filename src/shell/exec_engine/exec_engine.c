/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_engine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 03:52:38 by brda-sil          #+#    #+#             */
/*   Updated: 2022/09/27 23:37:54 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_engine(t_main *config)
{
	init_context_entry(config);
	prepare_cmds_1(config);
	init_cmds(config);
	init_redirection(config);
	init_get_cmd_paths(config);
	debug_init_redirection(config);
	set_signal_forked(1);
	config->last_return_value = exec_entry(config);
	set_signal_base();
	debug_print_post_exec(config);
	free_exec_entry(config);
}
