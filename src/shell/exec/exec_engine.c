/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_engine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 03:52:38 by brda-sil          #+#    #+#             */
/*   Updated: 2022/09/17 05:50:01 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// void	prepare_cmds(t_main *config)
// {
// 	t_block	*tmp;

// 	tmp = config->line_block;
// 	while (tmp)
// 	{
// 		if (tmp->block_id == STR)

// 	}
// }

void	exec_engine(t_main *config)
{
	init_context_entry(config);
	init_redirection(config);
	debug_init_redirection(config);
	exit(1);
	// prepare_cmds(config);
	// config->last_return_value = exec_entry(config->context);
	// free_exec_entry(config->context);
}

// echo pass > file1 > file2 > file3 > file4
