/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 08:51:17 by brda-sil          #+#    #+#             */
/*   Updated: 2022/09/22 15:55:33 by brda-sil         ###   ########.fr       */
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
	return (error_code);
}
