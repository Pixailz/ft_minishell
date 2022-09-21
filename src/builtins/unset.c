/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 05:03:33 by pmailly           #+#    #+#             */
/*   Updated: 2022/09/21 06:21:10 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	unset(char *var, t_lst_env **env)
{
	t_lst_env	*tmp;

	tmp = NULL;
	while (*env)
	{
		if (!ft_strcmp_env(var, (*env)->key))
			break ;
		tmp = *env;
		*env = (*env)->next;
	}
	if (!*env)
		return ;
	else if (!tmp)
	{
		tmp = *env;
		*env = (*env)->next;
		free(tmp->key);
		free(tmp->value);
		free(tmp);
	}
	else
	{
		free(tmp->key);
		free(tmp->value);
		free(tmp);
	}
}