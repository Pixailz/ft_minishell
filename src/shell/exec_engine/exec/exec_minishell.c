/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_minishell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 22:50:17 by brda-sil          #+#    #+#             */
/*   Updated: 2022/09/25 00:15:44 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exec_minishell(t_main *config)
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
	return (0);
}
