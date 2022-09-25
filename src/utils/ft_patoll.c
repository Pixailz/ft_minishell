/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_patoll.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 00:34:32 by brda-sil          #+#    #+#             */
/*   Updated: 2022/09/25 01:01:49 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_is_good_long_long(t_int64 n, int neg)
{
	int	is_good;

	is_good = True;
	if (neg == 1)
	{
		if (n > LLONG_MAX || n < 0)
			is_good = False;
	}
	else
	{
		if ((n * neg) < LLONG_MIN || (n * neg) > 0)
			is_good = False;
	}
	return (is_good);
}

static t_int64	ft_atoll_protected(char *nstr, int *has_overflow)
{
	char	*nptr;
	t_int64	to_dec;
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
	while (*nptr >= '0' && *nptr <= '9' && !*has_overflow)
	{
		if (!ft_is_good_long_long(to_dec, neg))
			*has_overflow = 1;
		to_dec = (to_dec * 0xA) + (*nptr++ & 0xF);
	}
	if (!ft_is_good_long_long(to_dec, neg))
		*has_overflow = 1;
	return (to_dec * neg);
}

t_int64	ft_patoll(char *nstr, int *has_overflow)
{
	t_int64	to_dec;

	to_dec = 0;
	if (has_overflow == FT_NULL)
		to_dec = ft_atol(nstr);
	else
		to_dec = ft_atoll_protected(nstr, has_overflow);
	return (to_dec);
}
