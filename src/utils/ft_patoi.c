/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_patoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 00:34:32 by brda-sil          #+#    #+#             */
/*   Updated: 2022/09/25 00:34:48 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_is_good_int(t_int64 n, int neg)
{
	int	is_good;

	is_good = True;
	if (neg == 1)
	{
		if (n > INT_MAX || n < 0)
			is_good = False;
	}
	else
	{
		if ((n * neg) < INT_MIN || (n * neg) > 0)
			is_good = False;
	}
	return (is_good);
}

int	ft_patoi(char *nstr, int *has_overflow)
{
	char	*nptr;
	int		to_dec;
	int		neg;

	to_dec = 0;
	neg = 1;
	nptr = nstr;
	*has_overflow = 0;
	while (*nptr == ' ' || (*nptr >= '\t' && *nptr <= '\r'))
		nptr++;
	if ((*nptr == '+' || *nptr == '-'))
		if (*nptr++ == '-')
			neg = ~(neg - 1);
	while (*nptr >= '0' && *nptr <= '9')
	{
		if (!ft_is_good_int(to_dec, neg))
		{
			*has_overflow = 1;
			break ;
		}
		to_dec = (to_dec * 0xA) + (*nptr++ & 0xF);
	}
	if (!ft_is_good_int(to_dec, neg))
		*has_overflow = 1;
	return (to_dec * neg);
}
