/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 20:20:23 by brda-sil          #+#    #+#             */
/*   Updated: 2022/09/22 01:09:18 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	debug_print_entry(int type, void *ptr)
{
	if (!DEBUG)
		return ;
	if (type == NONE)
		return ;
	return ((void)ptr);
}

void	debug_print_post_exec(t_main *config)
{
	if (config->last_return_value == 0)
		ft_printf_fd(LOG_FD, "  %s post_exec [0]\n", GREEN_PLUS);
	else if (config->last_return_value == 130)
		ft_printf_fd(LOG_FD, "  %s post_exec [130]\n", ORANGE_STAR);
	else
		ft_printf_fd(LOG_FD, "  %s post_exec [%d]\n", RED_MINUS, \
			config->last_return_value);
}
