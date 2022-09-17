/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_init_redirection.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 05:13:49 by brda-sil          #+#    #+#             */
/*   Updated: 2022/09/17 22:02:49 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	debug_print_redir_2(t_redirection *lst, int mode, int id, int counter)
{
	if (mode)
	{
		if (lst->is_double)
			ft_printf_fd(LOG_FD, "cmd[%d]->double_out_redir[%d] [%s]\n", id, \
				counter, lst->content);
		else
			ft_printf_fd(LOG_FD, "cmd[%d]->out_redir[%d] [%s]\n", \
				id, counter, lst->content);
	}
	else
	{
		if (lst->is_double)
			ft_printf_fd(LOG_FD, "cmd[%d]->double_in_redir[%d] [%s]\n", id, \
				counter, lst->content);
		else
			ft_printf_fd(LOG_FD, "cmd[%d]->in_redir[%d] [%s]\n", \
				id, counter, lst->content);
	}
}

void	debug_print_redir_1(t_redirection *lst, int mode, int id)
{
	int	counter;

	counter = 0;
	while (lst)
	{
		debug_print_redir_2(lst, mode, id, counter);
		lst = lst->next;
		counter++;
	}
}

void	debug_init_redirection(t_main *config)
{
	int	counter;

	counter = 0;
	while (counter < config->context->cmd_nb)
	{
		debug_print_cmd(config->context->cmd[counter], counter);
		counter++;
	}
}
