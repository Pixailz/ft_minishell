/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_export_utils_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 00:46:10 by brda-sil          #+#    #+#             */
/*   Updated: 2022/09/20 00:29:45 by brda-sil         ###   ########.fr       */
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
	envlst = FT_NULL;
	while (env[++i] != FT_NULL)
		ft_lstadd_back_env(&envlst, ft_lstnew_env(env[i]));
	index_env_lst(&envlst);
	return (envlst);
}

void	unlink_key_value(char *var_env, char **key, char **value)
{
	int	i;

	i = 0;
	while (var_env[i] && var_env[i] != '=')
		i++;
	if (!var_env[i])
	{
		*key = ft_substr(var_env, 0, i);
		*value = FT_NULL;
	}
	else
	{
		i++;
		*key = ft_substr(var_env, 0, i);
		while (--i > 0)
			var_env++;
		var_env++;
		*value = ft_strdup(var_env);
	}
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
			if (tmp == FT_NULL)
				return ;
		}
		index_env_lst2(*envlst, &tmp, &tmp2, &i);
	}
	return ;
}
