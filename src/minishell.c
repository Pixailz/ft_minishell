/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 23:57:29 by brda-sil          #+#    #+#             */
/*   Updated: 2022/09/01 02:40:35 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_lst_env  *env_to_lst(char **env);

char	**do_something_with_argv(char **argv)
{
	return (argv);
}

<<<<<<< HEAD
int	main(int ac, char **av, char **env)
{
	env_to_lst(env);
}

// int	main(int ac, char **av, char **env)
// {
//  	t_list *test;
//  	(void)ac;
//  	test = ft_better_split(av[1]);
//  	while (test != NULL)
//  	{
//  		printf("%s\n", (char *)test->content);
//  		test = test->next;
//  	}
// }

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
=======
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
>>>>>>> main
