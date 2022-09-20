/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_status_prompt.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 00:14:52 by brda-sil          #+#    #+#             */
/*   Updated: 2022/09/20 00:50:36 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_status_prompt(t_main *config)
{
	char	*status;

	if (config->last_return_value == 0)
		status = ft_strdup(GREEN_PLUS);
	else if (g_last_return_value == 130)
		status = ft_strdup(ORANGE_STAR);
	else
		status = ft_strdup(RED_MINUS);
	return (status);
}
