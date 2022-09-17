/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_better_strjoin.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 01:10:33 by brda-sil          #+#    #+#             */
/*   Updated: 2022/09/17 01:10:49 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_better_strjoin(char *s1, char *s2)
{
	t_size	size;
	char	*ptr;

	if (!s1 && !s2)
		return (FT_NULL);
	else if (s1 && !s2)
		return (s1);
	else if (!s1 && s2)
	{
		return (s2);
	}
	size = ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1;
	ptr = ft_calloc(0b1, size + 0b1);
	if (!ptr)
		return (FT_NULL);
	ptr[size] = 0;
	ft_strcpy(ptr, (char *)s1);
	ft_strcat(ptr, (char *)s2);
	free(s1);
	free(s2);
	return (ptr);
}
