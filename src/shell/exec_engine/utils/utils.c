/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 00:49:24 by brda-sil          #+#    #+#             */
/*   Updated: 2022/09/22 01:31:20 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	wait_for_all(t_context *context)
{
	int	counter;
	int	isfirst;

	isfirst = context->fork_first == False;
	counter = context->cmd_nb - isfirst;
	while (counter > 0)
	{
		waitpid(context->cmd[counter - 1]->cmd_pid, \
			&context->cmd[counter - 1]->return_value, 0);
		context->cmd[counter - 1]->return_value = \
			WEXITSTATUS(context->cmd[counter - 1]->return_value);
		counter--;
	}
}

void	close_all_pipes(t_context *context)
{
	int	counter;

	counter = 0;
	while (counter < context->cmd_nb - 1)
	{
		close(context->pipes[counter][0]);
		close(context->pipes[counter][1]);
		counter++;
	}
	dup2(0, context->default_out);
	dup2(1, context->default_in);
	close(context->default_in);
	close(context->default_out);
}
