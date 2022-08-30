/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 00:03:22 by brda-sil          #+#    #+#             */
/*   Updated: 2022/08/30 16:21:45 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_splitb_get_word(char *str, char delim, char *encl)
{
	int		count;
	int		have_encl;
	char	tmp_delim;

	count = 0;
	while (*str)
	{
		while (*str && *str == delim)
			str++;
		if (*str && *str != delim)
			count++;
		have_encl = ft_strcchr(encl, *str);
		if (have_encl)
		{
			tmp_delim = *str;
			str++;
			while (*str && *str != tmp_delim)
				str++;
			str++;
		}
		else
			while (*str && *str != delim && !ft_strcchr(encl, *str))
				str++;
	}
	return (count);
}

int	ft_splitb_get_size(char *str, char delim, char *encl)
{
	int		count;
	int		have_encl;
	char	tmp_delim;

	count = 0;
	while (*str)
	{
		while (*str && *str == delim)
			str++;
		if (*str && *str != delim)
			count++;
		have_encl = ft_strcchr(encl, *str);
		if (have_encl)
		{
			tmp_delim = *str;
			str++;
			while (*str && *str != tmp_delim)
				str++;
			str++;
		}
		else
			while (*str && *str != delim && !ft_strcchr(encl, *str))
				str++;
	}
	return (count);
}

char	**ft_splitb(char *s, char delim, char *encl)
{
	char	**tab;
	int		tab_len;
	int		counter;

	if (!s)
		return (NULL);
	tab_len = ft_splitb_get_size(s, delim, encl);
	tab = (char **)malloc(sizeof(char *) * (tab_len + 1));
	counter = 0;
	while (counter < tab_len)
		tab[counter++] = ft_splitb_get_word(s, delim, encl);
	return (tab);
}
