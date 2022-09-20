/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_prompt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 21:13:27 by brda-sil          #+#    #+#             */
/*   Updated: 2022/09/19 23:58:44 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	debug_prompt_base(t_main *config)
{
	ft_printf_fd(LOG_FD, "%s config:\n", BLUE_STAR);
	ft_printf_fd(LOG_FD, "   %s prompt_base\n", GREEN_PLUS);
	ft_printf_fd(LOG_FD, "      %s config->base_prompt [%s]\n", \
											ORANGE_STAR, config->prompt_base);
}

void	debug_prompt(t_main *config)
{
	ft_printf_fd(LOG_FD, "   %s prompt:\n", GREEN_PLUS);
	ft_printf_fd(LOG_FD, "      %s config->home [%s]\n", \
											ORANGE_STAR, config->home);
	ft_printf_fd(LOG_FD, "      %s config->cwd [%s]\n", \
											ORANGE_STAR, config->cwd);
	ft_printf_fd(LOG_FD, "      %s config->prompt [%s]\n", \
											ORANGE_STAR, config->prompt);
}
