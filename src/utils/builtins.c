/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 08:27:04 by brda-sil          #+#    #+#             */
/*   Updated: 2022/09/22 07:16:44 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_builtin(t_cmd *cmd)
{
	if (cmd->command[0] == FT_NULL)
		return (NONE);
	else if (!ft_strncmp(cmd->command[0], "cd", 2))
		return (CD);
	else if (!ft_strncmp(cmd->command[0], "pwd", 3))
		return (PWD);
	else if (!ft_strncmp(cmd->command[0], "echo", 4))
		return (ECHOO);
	else if (!ft_strncmp(cmd->command[0], "export", 6))
		return (EXPORT);
	else if (!ft_strncmp(cmd->command[0], "env", 3))
		return (ENV);
	else if (!ft_strncmp(cmd->command[0], "unset", 5))
		return (UNSET);
	return (NOT_BUILTIN);
}

t_bool	get_fork_first(int type)
{
	int	error_code;

	error_code = True;
	if (type == CD || type == UNSET || type == EXPORT)
		error_code = False;
	return (error_code);
}

void	get_builtins(t_main *config)
{
	int		counter;
	t_cmd	*cmd;

	counter = 0;
	config->context->fork_first = True;
	while (counter < config->context->cmd_nb)
	{
		cmd = config->context->cmd[counter];
		cmd->builtin = get_builtin(cmd);
		counter++;
		if (config->context->cmd_nb == 1 && !get_fork_first(cmd->builtin))
			config->context->fork_first = False;
	}
}
