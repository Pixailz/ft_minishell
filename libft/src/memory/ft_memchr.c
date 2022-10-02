/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 01:30:06 by brda-sil          #+#    #+#             */
/*   Updated: 2022/09/28 18:00:21 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_memory.h"

char	*ft_memchr(char *buf, unsigned char c)
{
	if (!buf)
		return (FT_NULL);
	while (*buf && *buf != c)
		buf++;
	if (!*buf)
		return (FT_NULL);
	return (++buf);
}
