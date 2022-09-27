/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 05:35:55 by brda-sil          #+#    #+#             */
/*   Updated: 2022/09/26 12:36:09 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exit_check_shlvl(t_main *config)
{
	char	*shlvl_str;
	char	*shlvl_new;
	int		shlvl;

	shlvl_str = get_env("SHLVL", config->env);
	shlvl = ft_atoi(shlvl_str);
	if (shlvl != 1)
	{
		shlvl_str = ft_itoa(shlvl - 1);
		shlvl_new = ft_strjoin("SHLVL=", shlvl_str);
		free(shlvl_str);
		export_var_to_env(&config->env, shlvl_new);
		free(shlvl_new);
		return (False);
	}
	return (True);
}

void	builtin_exit_post_exec(t_cmd *cmd, t_main *config)
{
	int	exit_code;

	exit_code = config->last_return_value;
	if (cmd->return_value == 1)
	{
		if (exit_check_exit_code(cmd->command[1]))
			exit_code = exit_get_exit_code(cmd->command[1]);
		else
		{
			ft_printf("minishell: exit: %s: numeric argument required\n", \
				cmd->command[1]);
			exit_code = 2;
		}
	}
	if (cmd->return_value == 2)
		ft_printf("minishell: exit: too many arguments\n", cmd->command[1]);
	else
	{
		if (exit_check_shlvl(config))
		{
			free_config_entry(config);
			exit(exit_code);
		}
	}
	cmd->return_value = exit_code;
}

int	exit_get_exit_code(char *exit_code)
{
	long long	code;

	code = ft_patoll(exit_code, 0);
	while (code < 0)
		code += 256;
	code = code % 256;
	return (code);
}

int	exit_check_exit_code(char *exit_code)
{
	int	is_alpha;
	int	counter;
	int	has_overflow;

	counter = 0;
	is_alpha = 1;
	ft_patoll(exit_code, &has_overflow);
	if (has_overflow)
		is_alpha = 0;
	if (exit_code[counter] == '-')
		counter += 1;
	while (exit_code[counter] && is_alpha)
	{
		if (ft_isalpha(exit_code[counter]))
			is_alpha = 0;
		counter++;
	}
	return (is_alpha);
}

int	builtin_exit(t_cmd *cmd, t_main *config)
{
	if (!config->context->fork_first)
		ft_printf("exit\n");
	if (!have_args(cmd))
		return (0);
	if (have_multiple_args(cmd))
		return (2);
	return (1);
}
