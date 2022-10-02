/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 08:56:14 by brda-sil          #+#    #+#             */
/*   Updated: 2022/10/02 16:45:36 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	builtin_cd_update_pwd(t_main *config)
{
	char	*tmp_1;

	tmp_1 = get_cwd();
	set_env("PWD", tmp_1, &config->env);
	free(tmp_1);
}

int	cd_get_error_code(t_cmd *cmd)
{
	int	isdir;

	isdir = ft_isdir(cmd->command[1], 0);
	if (isdir == 2)
	{
		ft_printf_fd(STDERR_FILENO, \
			"minishell: cd: %s: Not a directory\n", cmd->command[1]);
		return (1);
	}
	else if (isdir == 0)
	{
		ft_printf_fd(STDERR_FILENO, \
			"minishell: cd: %s: No such file or directory\n", cmd->command[1]);
		return (1);
	}
	else if (!ft_iscdable(cmd->command[1]))
	{
		ft_printf_fd(STDERR_FILENO, \
			"minishell: cd: %s: Permission denied\n", cmd->command[1]);
		return (1);
	}
	return (0);
}

int	builtin_cd(t_cmd *cmd, t_main *config)
{
	char	*to_change;
	int		error_code;

	error_code = 0;
	if (have_args(cmd))
	{
		error_code = have_multiple_args(cmd);
		if (error_code)
		{
			ft_printf_fd(STDERR_FILENO, \
				"minishell: cd: %s: too many arguments\n", cmd->command[1]);
			return (1);
		}
		to_change = cmd->command[1];
	}
	else
		to_change = get_env("HOME", config->env);
	if (ft_strlen(to_change) != 0)
		if (chdir(to_change) == -1)
			error_code = cd_get_error_code(cmd);
	return (error_code);
}
