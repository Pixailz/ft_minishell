/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 13:17:18 by pix               #+#    #+#             */
/*   Updated: 2022/07/01 12:03:53 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_integer.h"

/**
 * @brief			Length of an integer.
 *
 * @param void_nbr	Integer to take the size of.
 *
 * @return (t_size)	The length of nb, if number is negative, add +1 for the '-'.
 */
t_size	ft_nbrlen(const void *void_nbr)
{
	t_size	size;
	t_int64	nb;

	size = 0;
	nb = (t_int64)void_nbr;
	if (nb < 0)
	{
		nb = ~(nb - 1);
		size++;
	}
	while (nb && ++size)
		nb /= 10;
	return (size);
}
