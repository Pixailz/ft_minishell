/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 20:03:48 by brda-sil          #+#    #+#             */
/*   Updated: 2022/09/22 06:43:57 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	have_args(t_cmd *cmd)
{
	int	error_code;

	error_code = 0;
	if (cmd->command[0] != FT_NULL)
		if (cmd->command[1] != FT_NULL)
			error_code = 1;
	return (error_code);
}

t_bool	have_multiple_args(t_cmd *cmd)
{
	return (cmd->command[2] != FT_NULL);
}
