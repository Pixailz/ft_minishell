/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_redirection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 05:13:49 by brda-sil          #+#    #+#             */
/*   Updated: 2022/09/22 01:25:22 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	debug_print_redir_2(t_redirection *lst, int mode, int counter)
{
	if (mode)
	{
		if (lst->is_double)
			ft_printf_fd(LOG_FD, "  %s cmd->double_out_redir[%d] [%s]\n", \
				ORANGE_STAR, counter, lst->content);
		else
			ft_printf_fd(LOG_FD, "  %s cmd->out_redir[%d] [%s]\n", \
				ORANGE_STAR, counter, lst->content);
	}
	else
	{
		if (lst->is_double)
			ft_printf_fd(LOG_FD, "  %s cmd->double_in_redir[%d] [%s]\n", \
				ORANGE_STAR, counter, lst->content);
		else
			ft_printf_fd(LOG_FD, "  %s cmd->in_redir[%d] [%s]\n", \
				ORANGE_STAR, counter, lst->content);
	}
}

void	debug_print_redir_1(t_redirection *lst, int mode)
{
	int	counter;

	counter = 0;
	while (lst)
	{
		debug_print_redir_2(lst, mode, counter);
		lst = lst->next;
		counter++;
	}
}

void	debug_init_redirection(t_main *config)
{
	int	counter;

	counter = 0;
	ft_printf_fd(LOG_FD, "%s execution:\n", BLUE_STAR);
	if (config->context->fork_first)
		ft_printf_fd(LOG_FD, "  %s fork_first?: [True]\n", GREEN_PLUS);
	else
		ft_printf_fd(LOG_FD, "  %s fork_first?: [False]\n", RED_MINUS);
	while (counter < config->context->cmd_nb)
	{
		ft_printf_fd(LOG_FD, "  %s cmd[%d]\n", GREEN_PLUS, counter);
		debug_print_cmd(config->context->cmd[counter]);
		counter++;
	}
}
