/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 20:20:23 by brda-sil          #+#    #+#             */
/*   Updated: 2022/09/25 05:01:16 by brda-sil         ###   ########.fr       */
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
	t_context	*cont;

	cont = config->context;
	if (cont->cmd_nb == 1 && (cont->cmd[0]->builtin == EXIT \
			|| cont->cmd[0]->builtin == MINISHELL))
		ft_printf_fd(LOG_FD, "      %s SHLVL [%s]\n", ORANGE_STAR, \
			get_env("SHLVL", config->env));
	if (config->last_return_value == 0)
		ft_printf_fd(LOG_FD, "  %s post_exec [0]\n", GREEN_PLUS);
	else if (config->last_return_value == 130)
		ft_printf_fd(LOG_FD, "  %s post_exec [130]\n", ORANGE_STAR);
	else
		ft_printf_fd(LOG_FD, "  %s post_exec [%d]\n", RED_MINUS, \
			config->last_return_value);
}
