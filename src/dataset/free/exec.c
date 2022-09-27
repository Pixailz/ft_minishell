/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 00:17:59 by brda-sil          #+#    #+#             */
/*   Updated: 2022/09/25 07:18:05 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_exec_entry(t_main *config)
{
	free_cmds(config->context);
	if (config->context->path)
		free_char_pointer_pointer(config->context->path);
	free_pipes(config->context);
	free_t_block(config->line_block);
	close(config->context->default_in);
	close(config->context->default_out);
	free(config->context);
	config->context = FT_NULL;
}
