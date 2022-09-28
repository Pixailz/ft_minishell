/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 04:10:16 by brda-sil          #+#    #+#             */
/*   Updated: 2022/09/22 04:10:35 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv)
{
	int	error_code;

	if (argc != 2)
		return (ft_error("only one arg", 1));
	error_code = ft_isdir(argv[1]);
	if (!error_code)
		ft_printf("%s is a dir\n");
	else if (error_code == 2)
		ft_printf("%s do not exists\n");
	else if (error_code == 1)
		ft_printf("%s is not a dir\n");
	return (0);
}
