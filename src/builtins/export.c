/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmailly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 03:22:16 by pmailly           #+#    #+#             */
/*   Updated: 2022/08/30 03:22:19 by pmailly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_lst_env	*ft_lstadd_back_env(t_lst_env **lst, t_lst_env *new)
{
	t_lst_env	*ptr;

	if (!lst || !*lst)
	{
		*lst = new;
		return (*lst);
	}
	ptr = *lst;
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = new;
	return (ptr->next);
}

static void    unlink_key_value(char   *var_env, char  **key, char **value)
{
    int i;

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

static t_lst_env	*ft_lstnew_env(void *env)      
{
	t_lst_env	*ptr;

	ptr = (t_lst_env *)malloc(sizeof(t_lst_env));
	if (!ptr)
		return (FT_NULL);
    unlink_key_value(env, (char **)&ptr->key, (char **)&ptr->value);
	ptr->next = FT_NULL;
	return (ptr);
}

t_lst_env  *env_to_lst(char **env)
{
    t_lst_env    *envlst;
    int         i;

    i = -1;
    envlst = NULL;
    while (env[++i] != NULL)
        ft_lstadd_back_env(&envlst, ft_lstnew_env(env[i]));
    i = -1;
    while (envlst != NULL)
    {
        printf("%s%s\n", (char *)envlst->key, (char *)envlst->value);
        envlst = envlst->next;
    }
}