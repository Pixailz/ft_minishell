/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 20:20:23 by brda-sil          #+#    #+#             */
/*   Updated: 2022/09/21 05:40:47 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	debug_print(int type, void *ptr)
{
	if (!DEBUG)
		return ;
}

void	debug_print_question_mark(t_main *config)
{
	ft_printf_fd(LOG_FD, "question mark [%d]\n", config->last_return_value);
}

void	debug_print_post_exec(t_main *config)
{
	ft_printf_fd(LOG_FD, "post_exec [%d]\n", config->last_return_value);
}
