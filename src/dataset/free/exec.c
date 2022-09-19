/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 00:17:59 by brda-sil          #+#    #+#             */
/*   Updated: 2022/09/19 02:44:51 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_exec_entry(t_main *config)
{
	ft_printf_fd(LOG_FD, "free_exec_entry\n");
	free_cmds(config->context);
	free_char_pointer_pointer(config->context->path);
	free_pipes(config->context);
	free_t_block(config->line_block);
	free(config->context);
	config->context = FT_NULL;
}
