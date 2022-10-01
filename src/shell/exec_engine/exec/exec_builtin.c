/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 08:51:17 by brda-sil          #+#    #+#             */
/*   Updated: 2022/10/02 00:03:32 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exec_builtin(t_cmd *cmd, t_main *config)
{
	int		error_code;

	error_code = 0;
	if (cmd->builtin == CD)
		error_code = builtin_cd(cmd, config);
	if (cmd->builtin == PWD)
		error_code = builtin_pwd(cmd);
	if (cmd->builtin == ECHOO)
		error_code = builtin_echo(cmd);
	if (cmd->builtin == EXPORT)
		error_code = builtin_export(cmd, config);
	if (cmd->builtin == ENV)
		error_code = builtin_env(config->env);
	if (cmd->builtin == UNSET)
		error_code = builtin_unset(cmd, config);
	if (cmd->builtin == EXIT)
		error_code = builtin_exit(cmd, config);
	if (cmd->builtin == MINISHELL)
	{
		increase_shlvl(config);
		error_code = 0;
	}
	return (error_code);
}
