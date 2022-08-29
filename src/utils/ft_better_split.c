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

void	ft_lstadd_backsplit(t_input **lst, t_input *new)
{
	t_input	*tmp;

	tmp = *lst;
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	else
		*lst = new;
}

t_input	*ft_lstnew_ps(char *s)
{
	t_input	*lst;

	lst = malloc(sizeof(t_input));
	if (!lst)
		return (NULL);
	lst->str = s;
	lst->next = NULL;
	return (lst);
}

t_input	*ft_better_split(char *s)
{
	t_input *input;
	int 	i;

	i = 0;
	input = NULL;
	while (*s == ' ')
		s++;
	while (*s)
	{
		if (s[i] == '"')
		{
			i++;
			while (s[i] && s[i] != '"')
				i++;
			ft_lstadd_backsplit(&input, ft_lstnew_ps(ft_substr(s, 0, i + 1)));
			i++;
			while (--i > 0)
				s++;
			if (*s)
				s++;
		}
		if (s[i] == '\'')
		{
			i++;
			while (s[i] && s[i] != '\'')
				i++;
			ft_lstadd_backsplit(&input, ft_lstnew_ps(ft_substr(s, 0, i + 1)));
			i++;
			while (--i > 0)
				s++;
			if (*s)
				s++;
		}
		if (s[i] == '<')
		{
			while (s[i] && s[i] == '<')
				i++;
			ft_lstadd_backsplit(&input, ft_lstnew_ps(ft_substr(s, 0, i)));
			i++;
			while (--i > 0)
				s++;
		}
		if (s[i] == '>')
		{
			while (s[i] && s[i] == '>')
				i++;
			ft_lstadd_backsplit(&input, ft_lstnew_ps(ft_substr(s, 0, i)));
			i++;
			while (--i > 0)
				s++;
		}
		while (*s && *s == ' ')
			s++;
		while (s[i] && !ft_strcchr(" '\"<>", s[i]))
			i++;
		if (*s)
			ft_lstadd_backsplit(&input, ft_lstnew_ps(ft_substr(s, 0, i)));
		i++;
		while (--i > 0)
			s++;
		while (*s && *s == ' ')
			s++;
	}
	return (input);
}