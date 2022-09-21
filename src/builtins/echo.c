/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 10:53:31 by brda-sil          #+#    #+#             */
/*   Updated: 2022/09/21 06:39:44 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtin_echo_have_params(t_cmd *cmd)
{
	int	have_n;
	int	have_n_real;
	int	counter;

	have_n = 1;
	counter = 1;
	have_n_real = 0;
	while (have_n)
	{
		have_n = is_params(cmd->command[counter], "n");
		if (have_n)
		{
			have_n_real = 1;
			counter++;
		}
	}
	if (have_n_real)
		return (counter - 1);
	return (0);
}

int	builtin_echo(t_cmd *cmd)
{
	int	counter;
	int	have_n;

	if (have_args(cmd))
	{
		ft_printf("\n");
		return (0);
	}
	counter = 1;
	have_n = builtin_echo_have_params(cmd);
	counter += have_n;
	while (cmd->command[counter])
	{
		ft_printf("%s", cmd->command[counter]);
		if (cmd->command[counter + 1] != FT_NULL)
			ft_printf(" ");
		else
			if (!have_n)
				ft_printf("\n");
		counter++;
	}
	return (0);
}
