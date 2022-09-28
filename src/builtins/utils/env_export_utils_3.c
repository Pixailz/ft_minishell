/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_export_utils_3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 17:54:42 by brda-sil          #+#    #+#             */
/*   Updated: 2022/09/28 17:55:13 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_strcmp_env_join(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2 && *s1 != '+' && *s2 != '=')
	{
		s2++;
		s1++;
	}
	if ((*s1 == '+' && (!(*s2) || *s2 == '=')))
		return (0);
	else
		return (1);
}

static void	unlink_key_value_join(char *var_env, char **key, char **value)
{
	int	i;

	i = 0;
	if (*key)
		free(*key);
	while (var_env[i] != '+')
		i++;
	*key = ft_better_strjoin(ft_substr(var_env, 0, i), ft_strdup("="));
	i += 2;
	while (--i > 0)
		var_env++;
	var_env++;
	if (!(*value))
		*value = ft_strdup(var_env);
	else
		*value = ft_better_strjoin(*value, ft_strdup(var_env));
}

static t_lst_env	*ft_lstnew_env_join(void *env)
{
	t_lst_env	*ptr;

	ptr = (t_lst_env *)malloc(sizeof(t_lst_env));
	if (!ptr)
		return (FT_NULL);
	ptr->index = 0;
	ptr->key = FT_NULL;
	ptr->value = FT_NULL;
	unlink_key_value_join(env, (char **)&ptr->key, (char **)&ptr->value);
	ptr->next = FT_NULL;
	return (ptr);
}

void	export_join(t_lst_env **envlst, char *var)
{
	t_lst_env	*tmp;

	tmp = *envlst;
	while (tmp != FT_NULL)
	{
		tmp = *envlst;
		while (tmp)
		{
			if (tmp && ft_strcmp_env_join(var, tmp->key) == 0)
			{
				unlink_key_value_join(var, (char **)&tmp->key,
					(char **)&tmp->value);
				return ;
			}
			tmp = tmp->next;
		}
	}
	ft_lstadd_back_env(envlst, ft_lstnew_env_join(var));
	tmp = *envlst;
	while (tmp != FT_NULL)
	{
		tmp->index = 0;
		tmp = tmp->next;
	}
	index_env_lst(*envlst);
}
