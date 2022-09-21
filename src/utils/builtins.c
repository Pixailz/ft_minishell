/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_builtins.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 08:27:04 by brda-sil          #+#    #+#             */
/*   Updated: 2022/09/21 01:02:31 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_builtin(t_cmd *cmd)
{
	if (!ft_strncmp(cmd->command[0], "cd", 2))
		return (CD);
	else if (!ft_strncmp(cmd->command[0], "pwd", 3))
		return (PWD);
	else if (!ft_strncmp(cmd->command[0], "echo", 4))
		return (ECHO);
	else if (!ft_strncmp(cmd->command[0], "export", 6))
		return (EXPORT);
	return (NONE);
}

t_bool	get_fork_last(int type)
{
	int	error_code;

	error_code = False;
	if (type == CD || type == EXPORT)
		error_code = True;
	return (error_code);
}

void	get_builtins(t_main *config)
{
	int		counter;
	t_cmd	*cmd;

	counter = 0;
	config->context->fork_last = True;
	while (counter < config->context->cmd_nb)
	{
		cmd = config->context->cmd[counter];
		cmd->builtin = get_builtin(cmd);
		counter++;
		if (counter == config->context->cmd_nb)
			if (get_fork_last(cmd->builtin))
				config->context->fork_last = False;
	}
}
