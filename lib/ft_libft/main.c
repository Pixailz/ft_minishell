/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 09:12:28 by brda-sil          #+#    #+#             */
/*   Updated: 2022/07/06 16:15:19 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_print.h"
#include "libft_string.h"

int	main(int argc, char **argv)
{
	int	fd;

	if (argc != 2)
		return (ft_error("Not enought args", 1));
	fd = ft_atoi(argv[1]);
	ft_printf_fd(fd, "hello world from fd: %d\n", fd);
	return (0);
}
