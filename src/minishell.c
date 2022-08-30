/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 23:57:29 by brda-sil          #+#    #+#             */
/*   Updated: 2022/08/31 01:04:22 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**do_something_with_argv(char **argv)
{
	return (argv);
}

char	*push_string(char *str)
{
	str++;
	return (str);
}

int	main(void)
{
	char	**string_splitted;
	int		counter;
	// char	string[] = "echo -n 'test'";
	// char	string[] = "echo -n '  test  ' ";
	char	string[] = "echo ''\"\"";				// not working
	// char	string[] = "echo \"-n\" ' test '";
	// char	string[] = "echo \"\"n''";				// not working

	string_splitted = ft_splitb(string, ' ', "'\"");
	ft_printf("string ->   [%s]\n", string);
	// counter = 0;
	// while (string_splitted[counter])
	// {
	// 	ft_printf("splitted[%d] -> [%s]\n", counter, string_splitted[counter]);
	// 	counter++;
	// }
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
