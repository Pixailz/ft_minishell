/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 20:01:03 by brda-sil          #+#    #+#             */
/*   Updated: 2022/09/21 00:22:57 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	is_params(const char *argv, const char *options)
{
	char	*ptr_options;
	int		c_argv;

	c_argv = 0;
	if (!argv[c_argv] || argv[c_argv] != '-')
		return (FALSE);
	c_argv++;
	ptr_options = (char *)options;
	while (argv[c_argv])
	{
		if (!ft_strcchr(ptr_options, argv[c_argv]))
			return (FALSE);
		c_argv++;
	}
	return (TRUE);
}

t_bool	have_params(char *options, t_cmd *cmd)
{
	int	counter;

	counter = 1;
	while (cmd->command[counter])
	{
		if (is_params(cmd->command[counter], options))
			return (TRUE);
		counter++;
	}
	return (FALSE);
}
