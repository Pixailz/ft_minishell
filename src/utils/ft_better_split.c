/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_better_split.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 00:03:22 by brda-sil          #+#    #+#             */
/*   Updated: 2022/08/29 21:35:09 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	manage_quotes(char **s, char c, t_list **input)
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

static void	manage_symbols(char **s, char c, t_list **input)
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

static void	manage_strings(char **s, t_list **input)
{
	int	i;

	i = 0;
	while (**s && **s == ' ')
		(*s)++;
	while ((*s)[i] && !ft_strcchr(" '|\"<>", (*s)[i]))
		i++;
	if (i > 0)
		ft_lstadd_back(input, ft_lstnew(ft_substr(*s, 0, i)));
	i++;
	while (--i > 0)
		(*s)++;
	while (**s && **s == ' ')
		(*s)++;
}

t_list	*ft_better_split(char *s)
{
	t_list	*input;

	input = NULL;
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
	}
	return (input);
}