/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_splitb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 00:54:52 by brda-sil          #+#    #+#             */
/*   Updated: 2022/09/01 03:05:35 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
	"echo -n 'test'"
	"echo -n '  test  '"
	"echo   ''\"\""
	"echo \"-n\" ' test '"
	"echo \"\"n''"
	"test -f ./file.c && echo '  pass ' || echo '  failed '   a'"
	"ec'ho 'salut"
	"echo ''' salut\""					// not working
*/
int	main(int argc, char **argv, char **envp)
{
	char	**string_splitted;
	int		counter;
	char	*string;
	int		choice;

	if (argc != 2)
		return (ft_error("args", 1));
	string_splitted = ft_splitb(argv[1], ' ', "'\"");
	ft_printf("string    \t-> [%s]\n", argv[1]);
	counter = 0;
	while (string_splitted[counter])
	{
		ft_printf("splitted[%d]\t-> [%s]\n", counter, string_splitted[counter]);
		counter++;
	}
}
