/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tmpfile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 13:16:30 by brda-sil          #+#    #+#             */
/*   Updated: 2022/09/28 03:12:02 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
	int		counter;
	int		max;
	char	*name;

	counter = 0;
	max = 100;
	while (counter < max)
	{
		name = ft_tmpfile(0);
		ft_printf("[%s]\n", name);
		free(name);
		counter++;
	}
	return (0);
}

// int	main(void)
// {
// 	int		counter;
// 	int		max;

// 	counter = 0;
// 	max = 10;
// 	while (counter < max)
// 	{
// 		ft_printf("randint [%d]\n", ft_randint(-1, 1));
// 		counter++;
// 	}
// 	return (0);
// }
