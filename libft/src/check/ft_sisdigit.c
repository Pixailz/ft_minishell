/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sisdigit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 18:31:21 by pix               #+#    #+#             */
/*   Updated: 2022/10/14 14:18:37 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_check.h"

t_bool	ft_sisdigit(const char *str)
{
	char	*ptr;

	ptr = (char *)str;
	while (*ptr)
		if (!ft_isdigit(*ptr++))
			return (False);
	return (True);
}
