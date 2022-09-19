/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 00:49:48 by brda-sil          #+#    #+#             */
/*   Updated: 2022/09/19 02:01:56 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_pipes(t_context *context)
{
	int	counter;

	counter = 0;
	while (counter < context->cmd_nb - 1)
	{
		free(context->pipes[counter]);
		context->pipes[counter] = FT_NULL;
		counter++;
	}
	free(context->pipes);
	context->pipes = FT_NULL;
}
