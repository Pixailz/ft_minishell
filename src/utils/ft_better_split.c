/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_better_split.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 00:03:22 by brda-sil          #+#    #+#             */
/*   Updated: 2022/09/17 01:04:15 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	manage_quotes(char **s, char c, t_list **input)
{
	int	i;

	i = 0;
	if ((*s)[i] == c)
	{
		i++;
		while ((*s)[i] && (*s)[i] != c)
			i++;
		if (!(*s)[i])
			i = 0;
		ft_lstadd_back(input, ft_lstnew(ft_substr(*s, 0, i + 1)));
		i++;
		while (--i > 0)
			(*s)++;
		if (**s)
			(*s)++;
	}
}

void	manage_symbols(char **s, char c, t_list **input)
{
	int	i;

	i = 0;
	if ((*s)[i] == c)
	{
		while ((*s)[i] && (*s)[i] == c)
			i++;
		ft_lstadd_back(input, ft_lstnew(ft_substr(*s, 0, i)));
		i++;
		while (--i > 0)
			(*s)++;
	}
}

void	manage_strings(char **s, t_list **input)
{
	int	i;

	i = 0;
	while ((*s)[i] && !ft_strcchr(" '\"|<>", (*s)[i]))
		i++;
	if (i > 0)
		ft_lstadd_back(input, ft_lstnew(ft_substr(*s, 0, i)));
	i++;
	while (--i > 0)
		(*s)++;
}

t_list	*ft_better_split(char *s)
{
	t_list	*input;

	input = NULL;
	if (!s)
		return (NULL);
	while (*s == ' ')
		s++;
	while (*s)
	{
		manage_quotes(&s, '"', &input);
		manage_quotes(&s, '\'', &input);
		manage_symbols(&s, '<', &input);
		manage_symbols(&s, '>', &input);
		manage_symbols(&s, '|', &input);
		manage_strings(&s, &input);
		manage_symbols(&s, ' ', &input);
	}
	return (input);
}
