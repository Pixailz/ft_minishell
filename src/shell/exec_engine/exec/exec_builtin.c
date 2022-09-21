/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 08:51:17 by brda-sil          #+#    #+#             */
/*   Updated: 2022/09/21 05:52:35 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exec_builtin(t_cmd *cmd)
{
	int		error_code;

	error_code = 0;
	if (cmd->builtin == CD)
		error_code = builtin_cd(cmd);
	if (cmd->builtin == PWD)
		error_code = builtin_pwd(cmd);
	if (cmd->builtin == ECHO)
		error_code = builtin_echo(cmd);
	return (error_code);
}
