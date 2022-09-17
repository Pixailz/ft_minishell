/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 01:51:14 by brda-sil          #+#    #+#             */
/*   Updated: 2022/09/17 02:45:13 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	debug_print_line_block(t_block *line_block)
{
	int	counter;

	counter = 1;
	while (line_block)
	{
		ft_printf_fd(LOG_FD, "line_block[%d]\t[%d][%s]\n", counter, \
									line_block->block_id, line_block->block);
		line_block = line_block->next;
		counter++;
	}
}

void	debug_parse(t_main *config)
{
	ft_printf_fd(LOG_FD, "line_buffer\t\t[%s]\n", config->line_buffer);
	debug_print_line_block(config->line_block);
	ft_printf_fd(LOG_FD, "\n");
}
