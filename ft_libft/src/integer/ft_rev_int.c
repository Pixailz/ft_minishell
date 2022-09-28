/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 11:06:28 by stales            #+#    #+#             */
/*   Updated: 2022/09/28 17:59:55 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief			Reverse an integer
 *
 * @param nb		Number to reverse
 *
 * @return (int)	Reversed integer
 */
int	ft_rev_int(int nb)
{
	int	r;

	r = 0;
	while (nb)
	{
		r *= 10;
		r += (nb % 10);
		nb /= 10;
	}
	return (r);
}
