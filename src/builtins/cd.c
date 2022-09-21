/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 08:56:14 by brda-sil          #+#    #+#             */
/*   Updated: 2022/09/21 06:36:29 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	builtin_cd_update_pwd(t_main *config)
{
	char	*tmp_1;

	ft_printf_fd(LOG_FD, "update_pwd");
	tmp_1 = get_cwd();
	set_env("PWD", tmp_1, &config->env);
	free(tmp_1);
}

int	cd_get_error_code(t_cmd *cmd)
{
	if (access(cmd->command[1], F_OK) != 0)
	{
		ft_printf_fd(STDERR_FILENO, \
			"minishell: cd: %s: No such file or directory\n", cmd->command[1]);
		return (1);
	}
	else if (access(cmd->command[1], X_OK) != 0)
	{
		ft_printf_fd(STDERR_FILENO, \
			"minishell: cd: %s: Permission denied\n", cmd->command[1]);
		return (1);
	}
	return (0);
}

int	builtin_cd(t_cmd *cmd)
{
	char	*to_change;
	int		error_code;

	error_code = 0;
	if (cmd->command[1] != FT_NULL)
		to_change = cmd->command[1];
	else
		to_change = getenv("HOME");
	if (chdir(to_change))
		error_code = cd_get_error_code(cmd);
	return (error_code);
}
