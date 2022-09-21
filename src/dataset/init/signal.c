/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 00:20:16 by brda-sil          #+#    #+#             */
/*   Updated: 2022/09/20 19:47:26 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	init_signal(void)
{
	signal(SIGINT, signal_handler);
	signal(SIGQUIT, signal_handler);
	return (0);
}
