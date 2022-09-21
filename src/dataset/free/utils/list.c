/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 00:29:04 by brda-sil          #+#    #+#             */
/*   Updated: 2022/09/21 06:22:18 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_t_list(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	while (tmp)
	{
		tmp = lst->next;
		free(lst);
		lst = FT_NULL;
		lst = tmp;
	}
}

void	free_t_redirection(t_redirection *lst)
{
	t_redirection	*next;

	next = lst;
	while (next)
	{
		next = lst->next;
		free(lst->content);
		lst->content = FT_NULL;
		free(lst);
		lst = FT_NULL;
		lst = next;
	}
	free(lst);
	lst = FT_NULL;
}

void	free_t_block(t_block *lst)
{
	t_block	*tmp;

	tmp = lst;
	while (tmp)
	{
		tmp = lst->next;
		free(lst->block);
		lst->block = FT_NULL;
		free(lst);
		lst = tmp;
	}
	free(lst);
	lst = FT_NULL;
}

void	free_t_list_env(t_lst_env *lst)
{
	t_lst_env	*tmp;

	tmp = lst;
	while (tmp)
	{
		free(lst->key);
		lst->key = FT_NULL;
		free(lst->value);
		lst->value = FT_NULL;
		tmp = lst->next;
		free(lst);
		lst = FT_NULL;
		lst = tmp;
	}
}
