/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 00:49:24 by brda-sil          #+#    #+#             */
/*   Updated: 2022/09/18 21:12:17 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	wait_for_all(t_context *config)
{
	int	counter;

	counter = config->cmd_nb;
	while (counter > 0)
	{
		waitpid(config->cmd[counter - 1]->cmd_pid, \
									&config->cmd[counter - 1]->return_value, 0);
		if (WIFEXITED(config->cmd[counter - 1]->return_value))
			config->cmd[counter - 1]->return_value = \
							WEXITSTATUS(config->cmd[counter - 1]->return_value);
		counter--;
	}
}

void	print_command_not_found(t_context *context)
{
	int	counter;

	counter = 0;
	while (counter < context->cmd_nb)
	{
		while (!context->mutex_print)
			;
		context->mutex_print = 0;
		if (context->cmd[counter]->return_value == 127)
			ft_printf_fd(STDERR_FILENO, "%s: command not found\n", \
				context->cmd[counter]->command[0]);
		context->mutex_print = 1;
		counter++;
	}
}

void	close_all_pipes(t_context *config)
{
	int	counter;

	counter = 0;
	while (counter < config->cmd_nb - 1)
	{
		close(config->pipes[counter][0]);
		close(config->pipes[counter][1]);
		counter++;
	}
	dup2(0, config->default_out);
	dup2(1, config->default_in);
	close(config->default_in);
	close(config->default_out);
}
