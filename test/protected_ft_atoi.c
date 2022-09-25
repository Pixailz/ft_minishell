/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protected_ft_atoi.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 20:08:50 by brda-sil          #+#    #+#             */
/*   Updated: 2022/09/25 01:01:35 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv)
{
	int	n;
	int	has_overflow;

	if (argc != 2)
		return (ft_error("not enought args", 1));
	n = ft_patoll(argv[1], &has_overflow);
	if (has_overflow)
		ft_printf("error_occur\n");
	else
		ft_printf("[%s]->[%d]\n", argv[1], n);
	return (0);
}
