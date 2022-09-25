/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 03:22:16 by pmailly           #+#    #+#             */
/*   Updated: 2022/09/25 04:43:41 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	print_export(t_lst_env *envlst)
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
	return (0);
}

void	export_var_to_env(t_lst_env **envlst, char *var)
{
	t_lst_env	*tmp;

	tmp = *envlst;
	while (tmp != FT_NULL)
	{
		tmp = *envlst;
		while (tmp)
		{
			if (tmp && ft_strcmp_env(var, tmp->key) == 0)
			{
				unlink_key_value(var, (char **)&tmp->key, (char **)&tmp->value);
				return ;
			}
			tmp = tmp->next;
		}
	}
	ft_lstadd_back_env(envlst, ft_lstnew_env(var));
	tmp = *envlst;
	while (tmp != FT_NULL)
	{
		tmp->index = 0;
		tmp = tmp->next;
	}
	index_env_lst(*envlst);
}

int	print_export_failed(char *var)
{
	ft_printf_fd(STDERR_FILENO, \
		"minishell: export: `%s': not a valid identifier\n", var);
	return (1);
}

int	builtin_export(t_cmd *cmd, t_main *config)
{
	int	counter;
	int	is_good;

	if (!have_args(cmd))
		return (print_export(config->env));
	counter = 1;
	while (cmd->command[counter])
	{
		is_good = is_good_var_env(cmd->command[counter]);
		if (!is_good)
			break ;
		export_var_to_env(&config->env, cmd->command[counter]);
		counter++;
	}
	if (!is_good)
		return (print_export_failed(cmd->command[counter]));
	return (0);
}
