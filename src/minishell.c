/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 23:57:29 by brda-sil          #+#    #+#             */
/*   Updated: 2022/08/31 18:49:17 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**do_something_with_argv(char **argv)
{
	return (argv);
}

int	main(int argc, char **argv)
{
	char	**string_splitted;
	int		counter;
	char	*string;
	int		choice;

	if (argc != 2)
		return (ft_error("args", 1));
	// string = ft_strdup("echo -n 'test'");
	// string = ft_strdup("echo -n '  test  '");
	// string = ft_strdup("echo   ''\"\"");
	// string = ft_strdup("echo \"-n\" ' test '");
	// string = ft_strdup("echo \"\"n''");
	// string = ft_strdup("test -f ./file.c && echo '  pass ' || echo '  failed '   a'");
	// string = ft_strdup("ec'ho 'salut");
	string_splitted = ft_splitb(argv[1], ' ', "'\"");
	ft_printf("string    \t-> [%s]\n", argv[1]);
	counter = 0;
	while (string_splitted[counter])
	{
		ft_printf("splitted[%d]\t-> [%s]\n", counter, string_splitted[counter]);
		counter++;
	}
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
