/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 03:22:16 by pmailly           #+#    #+#             */
/*   Updated: 2022/09/17 01:26:12 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	unlink_key_value(char *var_env, char **key, char **value)
{
	int	i;

	i = 0;
	while (var_env[i] && var_env[i] != '=')
		i++;
	if (!var_env[i])
	{
		*key = ft_substr(var_env, 0, i);
		*value = NULL;
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

void	print_export(t_lst_env *envlst)
{
	t_lst_env	*tmp;
	int			i;

	i = 1;
	tmp = envlst;
	while (tmp != NULL)
	{
		tmp = envlst;
		while (tmp && tmp->index != i)
			tmp = tmp->next;
		if (tmp && tmp->value)
			printf("declare -x %s\"%s\"\n", (char *)tmp->key, (char *)tmp->value);
		else if (tmp)
			printf("declare -x %s\n", (char *)tmp->key);
		i++;
	}
}
