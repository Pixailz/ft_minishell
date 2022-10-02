/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:10:33 by brda-sil          #+#    #+#             */
/*   Updated: 2022/09/28 17:57:31 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_get_base(int c, const char *base)
{
	int	counter;

	counter = 0;
	while (base[counter])
	{
		if (c == base[counter])
			return (counter);
		counter++;
	}
	return (-1);
}
