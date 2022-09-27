/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_export_utils_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 01:00:01 by brda-sil          #+#    #+#             */
/*   Updated: 2022/09/25 04:44:15 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strcmp_env(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2 && *s1 != '=' && *s2 != '=')
	{
		s2++;
		s1++;
	}
	if ((*s1 == '=' && !(*s2)) || (*s2 == '=' && !(*s1)))
		return (0);
	else
		return ((unsigned char)*s1 - (unsigned char)*s2);
}

t_lst_env	*ft_lstnew_env(void *env)
{
	t_lst_env	*ptr;

	ptr = (t_lst_env *)malloc(sizeof(t_lst_env));
	if (!ptr)
		return (FT_NULL);
	ptr->index = 0;
	ptr->key = FT_NULL;
	ptr->value = FT_NULL;
	unlink_key_value(env, (char **)&ptr->key, (char **)&ptr->value);
	ptr->next = FT_NULL;
	return (ptr);
}

t_lst_env	*ft_lstadd_back_env(t_lst_env **lst, t_lst_env *new)
{
	t_lst_env	*ptr;

	if (!lst || !*lst)
	{
		*lst = new;
		return (*lst);
	}
	ptr = *lst;
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = new;
	return (ptr->next);
}
