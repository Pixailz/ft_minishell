/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 23:57:29 by brda-sil          #+#    #+#             */
/*   Updated: 2022/08/30 13:28:04 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**do_something_with_argv(char **argv)
{
	return (argv);
}

int	main(void)
{
	// char	string[] = "echo -n 'test'";
	// char	string[] = "echo -n '  test  ' ";
	// char	string[] = "echo \"-n\" ' test '";		// not working
	char	string[] = "echo \"\"-n\"\" 'test'";	// not working
	char	**string_splitted;
	int		counter;

	string_splitted = ft_better_split(string, ' ', "'\"");
	// string_splitted = ft_split(string, ' ');
	ft_printf("string -> [%s]\n", string);
	counter = 0;
	while (string_splitted[counter])
	{
		ft_printf("splitted[%d] -> [%s]\n", counter, string_splitted[counter]);
		counter++;
	}
	// splited = ft_better_split(argv[1], ' ');
	// counter = 0;
	// while (splited[counter])
	// {
	// 	ft_printf("splited[%d] : [%s]\n", counter, splited[counter]);
	// 	counter++;
	// }
	// return (0);
}

// int	main(int argc, char **argv)
// {
// 	t_main	config;

// 	if (argc != 1)
// 		return (ft_error("no arguments needed", 1));
// 	do_something_with_argv(argv);
// 	init_entry(&config);
// 	main_loop(&config);
// 	free_entry(&config);
// 	return (0);
// }
