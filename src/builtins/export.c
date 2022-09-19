/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 03:22:16 by pmailly           #+#    #+#             */
/*   Updated: 2022/09/19 00:37:26 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_export(t_lst_env *envlst)
{
	t_lst_env	*tmp;
	int			i;

	i = 1;
	tmp = envlst;
	while (tmp != FT_NULL)
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

void	export_var_to_env(t_lst_env **envlst, char *var)
{
	t_lst_env	*tmp;
	int			i;

	i = 1;
	tmp = *envlst;
	while (tmp != FT_NULL)
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
	while (tmp != FT_NULL)
	{
		tmp->index = 0;
		tmp = tmp->next;
	}
	index_env_lst(envlst);
}
