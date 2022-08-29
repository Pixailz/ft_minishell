/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_better_get_words.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 22:35:06 by brda-sil          #+#    #+#             */
/*   Updated: 2022/08/29 23:49:37 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	ft_push_string(char *str, char *c)
{
	char	*c_ptr;

	while (*str)
	{
		c_ptr = c;
		while (*c_ptr)
		{
			if (*str == *c_ptr)
			{
				while (*str == *c_ptr)
					str++;
				if (ft_strcchr(c, *(str + 1)))
				{
					c_ptr++;
					continue ;
				}
				while (*str == *c_ptr)
					str++;
				return (*c_ptr);
			}
			c_ptr++;
		}
		str++;
	}
	return (0);
}

int	ft_better_get_words(char *str, char *c)
{
	int		count;
	int		tmp_delim;

	count = 0;
	while (*str)
	{
		if (*str == ' ')
			while (*str == ' ')
				str++;
		tmp_delim = ft_strcchr(c, *str);
		if (*str && *str != tmp_delim)
			count++;
		while (*str != tmp_delim)
			str++;
	}
	return (count);
}
