/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_better_get_words.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 22:35:06 by brda-sil          #+#    #+#             */
/*   Updated: 2022/08/30 13:27:00 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_better_get_words(char *str, char delim, char *encl)
{
	int		count;
	char	tmp_delim;

	count = 0;
	while (*str)
	{
		while (*str && *str == delim)
			str++;
		tmp_delim = ft_strcchr(encl, *str);
		if (*str && *str != delim)
			count++;
		if (tmp_delim)
		{
			tmp_delim = encl[tmp_delim - 1];
			str++;
			while (*str && *str != tmp_delim)
				str++;
			continue ;
		}
		else
			while (*str && *str != delim)
				str++;
	}
	return (count);
}
