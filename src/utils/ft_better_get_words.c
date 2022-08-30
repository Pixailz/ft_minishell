/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_better_get_words.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 22:35:06 by brda-sil          #+#    #+#             */
/*   Updated: 2022/08/30 13:39:39 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_better_get_words(char *str, char delim, char *encl)
{
	int		count;
	int		have_delim;
	char	tmp_delim;

	count = 0;
	while (*str)
	{
		while (*str && *str == delim)
			str++;
		have_delim = ft_strcchr(encl, *str);
		if (*str && *str != delim)
			count++;
		if (have_delim)
		{
			tmp_delim = *str;
			str++;
			while (*str && *str != tmp_delim)
				str++;
			str++;
		}
		else
			while (*str && *str != delim)
				str++;
	}
	return (count);
}
