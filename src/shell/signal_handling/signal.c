/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 00:20:16 by brda-sil          #+#    #+#             */
/*   Updated: 2022/10/14 19:11:24 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_signal_forked(int mode)
{
	if (!mode)
		signal(SIGINT, &signal_handler_here_doc);
	else
	{
		signal(SIGQUIT, &signal_handler_forked);
		signal(SIGINT, &signal_handler_forked);
	}
}

void	set_signal_base(void)
{
	signal(SIGINT, &signal_handler);
	signal(SIGQUIT, SIG_IGN);
}
