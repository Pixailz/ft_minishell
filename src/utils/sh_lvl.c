/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_lvl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 00:00:17 by brda-sil          #+#    #+#             */
/*   Updated: 2022/10/02 00:06:01 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	increase_shlvl(t_main *config)
{
	char	*tmp_1;
	char	*tmp_2;
	int		tmp_int;

	tmp_1 = get_env("SHLVL", config->env);
	tmp_int = ft_atoi(tmp_1) + 1;
	tmp_2 = ft_itoa(tmp_int);
	tmp_1 = ft_strjoin("SHLVL=", tmp_2);
	free(tmp_2);
	export_var_to_env(&config->env, tmp_1);
	free(tmp_1);
}

void	decrease_shlvl(t_main *config)
{
	char	*tmp_1;
	char	*tmp_2;
	int		tmp_int;

	tmp_1 = get_env("SHLVL", config->env);
	tmp_int = ft_atoi(tmp_1) - 1;
	tmp_2 = ft_itoa(tmp_int);
	tmp_1 = ft_strjoin("SHLVL=", tmp_2);
	free(tmp_2);
	export_var_to_env(&config->env, tmp_1);
	free(tmp_1);
}

int	get_shlvl(t_main *config)
{
	char	*shlvl_str;
	int		shlvl;

	shlvl_str = get_env("SHLVL", config->env);
	shlvl = ft_atoi(shlvl_str);
	return (shlvl);
}

t_bool	exit_check_shlvl(t_main *config)
{
	if (get_shlvl(config) > config->base_shlvl)
	{
		decrease_shlvl(config);
		return (FALSE);
	}
	return (TRUE);
}
