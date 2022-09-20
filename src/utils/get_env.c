/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 22:54:09 by brda-sil          #+#    #+#             */
/*   Updated: 2022/09/19 22:54:43 by brda-sil         ###   ########.fr       */
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
