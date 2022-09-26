/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 08:27:04 by brda-sil          #+#    #+#             */
/*   Updated: 2022/09/26 02:23:37 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_good_builin(char *from, char *to)
{
	int	is_good;
	int	len_to;

	is_good = 1;
	len_to = ft_strlen(to);
	if (ft_strlen(from) != len_to)
		is_good = 0;
	else if (ft_strncmp(from, to, len_to))
		is_good = 0;
	return (is_good);
}

int	get_builtin(t_cmd *cmd)
{
	if (cmd->command[0] == FT_NULL)
		return (NONE);
	else if (is_good_builin(cmd->command[0], "cd"))
		return (CD);
	else if (is_good_builin(cmd->command[0], "pwd"))
		return (PWD);
	else if (is_good_builin(cmd->command[0], "echo"))
		return (ECHOO);
	else if (is_good_builin(cmd->command[0], "export"))
		return (EXPORT);
	else if (is_good_builin(cmd->command[0], "env"))
		return (ENV);
	else if (is_good_builin(cmd->command[0], "unset"))
		return (UNSET);
	else if (is_good_builin(cmd->command[0], "exit"))
		return (EXIT);
	else if (ft_isfile(cmd->command[0], S_IXUSR) == 1)
		return (MINISHELL);
	return (NOT_BUILTIN);
}

t_bool	get_fork_first(int type)
{
	int	error_code;

	error_code = True;
	if (type == CD || type == UNSET || type == EXPORT || type == EXIT)
		error_code = False;
	if (type == MINISHELL)
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
