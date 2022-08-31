/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 23:57:29 by brda-sil          #+#    #+#             */
/*   Updated: 2022/08/31 16:40:19 by brda-sil         ###   ########.fr       */
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
	choice = ft_atoi(argv[1]);
	if (choice == 1)
		string = ft_strdup("echo -n 'test'");
	if (choice == 2)
		string = ft_strdup("echo -n '  test  '");
	if (choice == 3)
		string = ft_strdup("echo   ''\"\"");
	if (choice == 4)
		string = ft_strdup("echo \"-n\" ' test '");
	if (choice == 5)
		string = ft_strdup("echo \"\"n''");
	if (choice == 6)
		string = ft_strdup("test -f ./file.c && echo '  pass ' || echo '  failed '   a'");
	string_splitted = ft_splitb(string, ' ', "'\"");
	ft_printf("string    \t-> [%s]\n", string);
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
