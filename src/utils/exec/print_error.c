/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 06:20:50 by brda-sil          #+#    #+#             */
/*   Updated: 2022/09/19 07:00:11 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	print_error_outfile(t_redirection *tmp)
{
	while (tmp)
	{
		if (access(tmp->content, W_OK) != 0)
		{
			ft_printf_fd(STDERR_FILENO, \
				"minishell: %s: Permission denied\n", tmp->content);
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

int	print_error_infile(t_redirection *tmp)
{
	while (tmp)
	{
		if (!tmp->is_double)
		{
			if (access(tmp->content, F_OK) != 0)
			{
				ft_printf_fd(STDERR_FILENO, \
					"minishell: %s: No such file or directory\n", tmp->content);
				return (1);
			}
			if (access(tmp->content, R_OK) != 0)
			{
				ft_printf_fd(STDERR_FILENO, \
					"minishell: %s: Permission denied\n", tmp->content);
				return (1);
			}
		}
		tmp = tmp->next;
	}
	return (0);
}

int	print_error_file(t_cmd *cmd)
{
	if (cmd->out_redir)
		if (print_error_outfile(cmd->out_redir))
			return (1);
	if (cmd->in_redir)
		if (print_error_infile(cmd->in_redir))
			return (1);
	return (0);
}

void	print_error(t_context *context)
{
	int	counter;
	int	error[0xffff];

	counter = context->cmd_nb - 1;
	while (counter >= 0)
	{
		error[counter] = print_error_file(context->cmd[counter]);
		counter--;
	}
	counter = 0;
	while (counter < context->cmd_nb)
	{
		if (!error[counter])
		{
			if (context->cmd[counter]->return_value == 127)
				ft_printf_fd(STDERR_FILENO, "%s: command not found\n", \
					context->cmd[counter]->command[0]);
			if (context->cmd[counter]->return_value == 126)
				ft_printf_fd(STDERR_FILENO, \
					"minishell: %s: Permission denied\n", \
						context->cmd[counter]->path);
		}
		counter++;
	}
}
