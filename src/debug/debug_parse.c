/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 01:51:14 by brda-sil          #+#    #+#             */
/*   Updated: 2022/09/20 00:04:14 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	debug_parse(t_main *config)
{
	ft_printf_fd(LOG_FD, "%s parsing:\n", BLUE_STAR);
	ft_printf_fd(LOG_FD, "   %s line_buffer [%s]\n", \
											GREEN_PLUS, config->line_buffer);
	ft_printf_fd(LOG_FD, "\n");
}
