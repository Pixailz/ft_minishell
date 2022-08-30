/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 00:03:22 by brda-sil          #+#    #+#             */
/*   Updated: 2022/08/31 01:03:12 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_splitb_get_word(char *str, char delim, char *encl, int *end)
{
	int			have_encl;
	char		tmp_delim;
	static int	begin = 0;

	while (str[begin] && str[begin] == delim)
		begin++;
	*end = begin;
	have_encl = ft_strcchr(encl, str[begin]);
	if (have_encl)
	{
		tmp_delim = str[begin];
		(*end)++;
		while (str[*end] && str[*end] != tmp_delim)
			(*end)++;
		(*end)++;
	}
	else
	{
		while (str[*end] && str[*end] != delim && !ft_strcchr(encl, str[*end]))
		{
			(*end)++;
		}
	}
	return (begin);
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

char	**ft_splitb_get_words(char *s, char delim, char *encl, int tab_size)
{
	int	counter;
	int	end;
	int	begin;

	while (counter < tab_len)
	{
		begin = ft_splitb_get_word(s_ptr, delim, encl, &end);
		ft_printf("begin ->   [%d]\n", begin);
		ft_printf("end   ->   [%d]\n", end - 1);
		ft_printf("s_ptr -> [%s]\n\n", s_ptr);
		s_ptr = s_ptr + ((end - begin) + 1);
		if (!s_str)
			break ;
		counter++;
	}
	return ((char **)0);
}

char	**ft_splitb(char *s, char delim, char *encl)
{
	char	**tab;
	int		tab_len;

	if (!s)
		return (NULL);
	tab_len = ft_splitb_get_size(s, delim, encl);
	tab = (char **)malloc(sizeof(char *) * (tab_len + 1));
	tab = ft_splitb_get_words(s, delim, encl, tab_size);
	return (tab);
}
