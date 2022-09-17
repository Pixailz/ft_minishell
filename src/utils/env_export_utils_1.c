/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_export_utils_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 00:46:10 by brda-sil          #+#    #+#             */
/*   Updated: 2022/09/17 01:03:28 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
 * print_env(envlst);
 * print_export(envlst);
 * export_var_to_env(&envlst, "SALUT=salut");
 * print_env(envlst);
 * print_export(envlst);
 */
t_lst_env	*env_to_lst(char **env)
{
	t_lst_env	*envlst;
	int			i;

	i = -1;
	envlst = NULL;
	while (env[++i] != NULL)
		ft_lstadd_back_env(&envlst, ft_lstnew_env(env[i]));
	index_env_lst(&envlst);
	return (envlst);
}

void	export_var_to_env(t_lst_env **envlst, char *var)
{
	t_lst_env	*tmp;
	int			i;

	i = 1;
	tmp = *envlst;
	while (tmp != NULL)
	{
		tmp = *envlst;
		while (tmp && tmp->index != i)
			tmp = tmp->next;
		if (tmp && ft_strcmp_env(var, tmp->key) == 0)
		{
			unlink_key_value(var, (char **)&tmp->key, (char **)&tmp->value);
			return ;
		}
		i++;
	}
	ft_lstadd_back_env(envlst, ft_lstnew_env(var));
	tmp = *envlst;
	while (tmp != NULL)
	{
		tmp->index = 0;
		tmp = tmp->next;
	}
	index_env_lst(envlst);
}

void	index_env_lst2(t_lst_env *lst, t_lst_env **tmp, t_lst_env **tmp2, int *i)
{
	*tmp2 = lst->next;
	while ((*tmp2)->next)
	{
		*tmp2 = (*tmp2)->next;
		if ((*tmp2)->index == 0 && ft_strcmp_env((*tmp)->key, (*tmp2)->key) > 0)
			*tmp = *tmp2;
	}
	(*tmp)->index = *i;
	(*i)++;
	*tmp = lst;
}

void	index_env_lst(t_lst_env **envlst)
{
	t_lst_env	*tmp;
	t_lst_env	*tmp2;
	int			i;
	int			len;

	i = 1;
	len = 0;
	tmp = *envlst;
	while (tmp)
	{
		len++;
		tmp = tmp->next;
	}
	tmp = *envlst;
	while (i <= len)
	{
		while (tmp->index != 0)
		{
			tmp = tmp->next;
			if (tmp == NULL)
				return ;
		}
		index_env_lst2(*envlst, &tmp, &tmp2, &i);
	}
	return ;
}
