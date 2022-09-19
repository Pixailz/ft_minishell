/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 23:57:29 by brda-sil          #+#    #+#             */
/*   Updated: 2022/09/19 02:57:52 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**do_something_with_argv(char **argv)
{
	return (argv);
}

int	main(int argc, char **argv, char **envp)
{
	t_main	config;
	int		return_value;

	if (argc != 1)
		return (ft_error("no arguments needed", 1));
	do_something_with_argv(argv);
	init_config_entry(&config, envp);
	main_loop(&config);
	return_value = config.last_return_value;
	free_config_entry(&config);
	return (return_value);
}
