/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 05:03:33 by pmailly           #+#    #+#             */
/*   Updated: 2022/09/22 15:55:20 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	unset2(t_lst_env *tmp, t_lst_env **env, t_lst_env *first)
{
	tmp->next = (*env)->next;
	free((*env)->key);
	if ((*env)->value)
		free((*env)->value);
	free((*env));
	*env = first;
	while (*env)
	{
		(*env)->index = 0;
		(*env) = (*env)->next;
	}
	*env = first;
}

void	unset(char *var, t_lst_env **env)
{
	t_lst_env	*tmp;
	t_lst_env	*first;

	tmp = NULL;
	first = *env;
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
		*env = (*env)->next;
		free(first->key);
		if (first->value)
			free(first->value);
		free(first);
	}
	else
		unset2(tmp, env, first);
	index_env_lst(*env);
}

int	builtin_unset(t_cmd *cmd, t_main *config)
{
	int	counter;

	if (!have_args(cmd))
		return (0);
	counter = 1;
	while (cmd->command[counter])
	{
		unset(cmd->command[counter], &config->env);
		counter++;
	}
	return (0);
}
