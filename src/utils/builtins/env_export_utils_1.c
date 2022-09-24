/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_export_utils_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 00:46:10 by brda-sil          #+#    #+#             */
/*   Updated: 2022/09/21 02:21:50 by brda-sil         ###   ########.fr       */
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
	index_env_lst(envlst);
	return (envlst);
}

void	unlink_key_value(char *var_env, char **key, char **value)
{
	int	i;

	i = 0;
	if (*key)
		free(*key);
	if (*value)
		free(*value);
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

void	index_env_lst(t_lst_env *env)
{
	t_lst_env	*tmp;
	t_lst_env	*first;
	int			i;

	i = 1;
	first = env;
	while (env)
	{
		env = first;
		while (env && env->index != 0)
			env = env->next;
		tmp = env;
		while (tmp)
		{
			tmp = tmp->next;
			while (tmp && (tmp->index != 0 || ft_strcmp_env(tmp->key, env->key) > 0))
				tmp = tmp->next;
			if (tmp)
				env = tmp;
			else
			{
				env->index = i;
				i++;
			}
		}
	}
}