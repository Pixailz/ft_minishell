/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 22:54:09 by brda-sil          #+#    #+#             */
/*   Updated: 2022/09/21 04:37:47 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_env(char *key, t_lst_env *env)
{
	while (env)
	{
		if (!ft_strcmp_env(key, env->key))
			break ;
		env = env->next;
	}
	if (env)
		return (env->value);
	return (FT_NULL);
}

void	set_env(char *key, char *value, t_lst_env **env)
{
	t_lst_env	*env_ptr;

	env_ptr = *env;
	while (env_ptr)
	{
		if (!ft_strcmp_env(key, env_ptr->key))
			break ;
		env_ptr = env_ptr->next;
	}
	if (env_ptr)
	{
		free(env_ptr->value);
		env_ptr->value = (void *)ft_strdup(value);
	}
}
