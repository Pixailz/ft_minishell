/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isfile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 21:05:26 by brda-sil          #+#    #+#             */
/*   Updated: 2022/09/24 23:45:50 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv)
{
	int	error_code;

	if (argc != 2)
		return (ft_error("only one arg", 1));
	error_code = ft_isfile(argv[1], S_IXUSR);
	ft_printf("error_code [%d]\n", error_code);
	return (0);
}
