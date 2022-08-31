/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 00:03:22 by brda-sil          #+#    #+#             */
/*   Updated: 2022/08/31 16:34:43 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_splitb_get_word(char **str, char delim, char *encl)
{
	int		have_encl;
	char	tmp_delim;
	char	*str_ptr;

	while (**str && **str == delim)
		(*str)++;
	str_ptr = *str;
	have_encl = ft_strcchr(encl, **str);
	if (have_encl)
	{
		tmp_delim = **str;
		str_ptr++;
		while (*str_ptr && *str_ptr != tmp_delim)
			str_ptr++;
		str_ptr++;
	}
	else
		while (*str_ptr && *str_ptr != delim && !ft_strcchr(encl, *str_ptr))
			str_ptr++;
	return (str_ptr - *str);
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

// char	**ft_splitb_get_words(char *s, char delim, char *encl)
// {
// 	int		counter;
// 	int		end;
// 	char	*s_ptr;

// 	end = 0;
// 	counter = 0;
// 	s_ptr = s;
// 	while (*s_ptr)
// 	{
// 		end = ft_splitb_get_word(&s_ptr, delim, encl);
// 		s_ptr = s_ptr + end;
// 		counter++;
// 	}
// 	return ((char **)0);
// }

char	**ft_splitb(char *s, char delim, char *encl)
{
	char	**tab;
	int		tab_len;
	int		counter;
	int		size;
	char	*s_ptr;

	if (!s)
		return (NULL);
	tab_len = ft_splitb_get_size(s, delim, encl);
	tab = (char **)malloc(sizeof(char *) * (tab_len + 1));
	size = 0;
	counter = 0;
	s_ptr = ft_strtrim(s, " ");
	while (*s_ptr)
	{
		size = ft_splitb_get_word(&s_ptr, delim, encl);
		tab[counter] = (char *)malloc(sizeof(char) * size);
		ft_strncpy(tab[counter], s_ptr, size);
		s_ptr = s_ptr + size;
		counter++;
	}
	return (tab);
}
