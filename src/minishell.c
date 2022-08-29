/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 23:57:29 by brda-sil          #+#    #+#             */
/*   Updated: 2022/08/29 21:24:58 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**do_something_with_argv(char **argv)
{
	return (argv);
}

int	main(int ac, char **av)
{
	t_input *test;

	(void)ac;
	test = ft_better_split(av[1]);
	while (test != NULL)
	{
		printf("%s\n", test->str);
		test = test->next;
	}
}

// int	main(int argc, char **argv)
// {
// 	char	**splited;
// 	int		counter;

// 	if (argc != 2)
// 		return (ft_error("args", 1));
// 	ft_printf("argv[1] : [%s]\n", argv[1]);
// 	splited = ft_better_split(argv[1]);
// 	counter = 0;
// 	while (splited[counter])
// 	{
// 		ft_printf("splited[%d] : [%s]\n", counter, splited[counter]);
// 		counter++;
// 	}
// 	return (0);
// }

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
