/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_to_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 00:42:14 by brda-sil          #+#    #+#             */
/*   Updated: 2022/10/02 01:23:21 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_size	env_get_size(t_lst_env *env)
{
	t_size	size;

	size = 0;
	while (env)
	{
		env = env->next;
		size++;
	}
	return (size);
}

char	*env_get_line(char *key, char *value)
{
	t_size	len_key;
	t_size	len_value;
	char	*line;

	len_key = ft_strlen(key);
	len_value = ft_strlen(value);
	line = (char *)ft_calloc(sizeof(char *), len_key + len_value + 1);
	ft_strncpy(line, key, len_key);
	ft_strncpy(&line[len_key], value, len_value);
	return (line);
}

char	**env_to_char(t_lst_env *env)
{
	char	**return_value;
	t_size	counter;
	t_size	len_env;

	len_env = env_get_size(env);
	return_value = (char **)ft_calloc(sizeof(char *), len_env + 1);
	if (!return_value)
		return (FT_NULL);
	counter = 0;
	while (counter < len_env)
	{
		return_value[counter] = env_get_line(env->key, env->value);
		counter++;
		env = env->next;
	}
	return (return_value);
}
