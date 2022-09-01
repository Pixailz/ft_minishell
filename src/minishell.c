/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 23:57:29 by brda-sil          #+#    #+#             */
/*   Updated: 2022/09/01 04:07:14 by brda-sil         ###   ########.fr       */
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

	if (argc != 1)
		return (ft_error("no arguments needed", 1));
	do_something_with_argv(argv);
	init_entry(&config, envp);
	main_loop(&config);
	free_entry(&config);
	return (0);
}
