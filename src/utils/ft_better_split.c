/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_better_split.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 00:03:22 by brda-sil          #+#    #+#             */
/*   Updated: 2022/08/26 00:23:36 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_get_words(char *str, char c)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (*str && *str == c)
			str++;
		if (*str == '\'')
		{
			if (*str && *str != '\'')
				count++;
			while (*str && *str != '\'')
				str++;
		}
		else if (*str == '"')
		{
			if (*str && *str != '"')
				count++;
			while (*str && *str != '"')
				str++;
		}
		else
		{
			if (*str && *str != c)
				count++;
			while (*str && *str != c)
				str++;
		}
	}
	return (count);
}

char	*ft_better_init_str(char *s, char c)
{
	int		i;
	char	*ptr;

	i = 0;
	if (s[i] == '\'')
	{
		while (s[i] && s[i] != '\'')
			i++;
	}
	else if (s[i] == '"')
	{
		while (s[i] && s[i] != '"')
			i++;
	}
	else
	{
		while (s[i] && s[i] != c)
			i++;
	}
	ptr = (char *)malloc(sizeof(char) * (i + 1));
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, s, i + 1);
	return (ptr);
}

char	**ft_better_split(char *s, char c)
{
	int		i[2];
	char	**ptr;

	if (!s)
		return (NULL);
	i[1] = ft_get_words(s, c);
	ptr = (char **)malloc(sizeof(char *) * (i[1] + 1));
	i[0] = -1;
	while (ptr && ++i[0] < i[1])
	{
		while (s[0] == c)
			s++;
		ptr[i[0]] = ft_better_init_str(s, c);
		if (!ptr[i[0]])
		{
			while (i[0] > 0)
				free(ptr[i[0]--]);
			free(ptr);
			return (NULL);
		}
		s = s + ft_strlen(ptr[i[0]]);
	}
	if (ptr)
		ptr[i[0]] = 0;
	return (ptr);
}
