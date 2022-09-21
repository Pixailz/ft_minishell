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

void    unset2(t_lst_env *tmp, t_lst_env **env, t_lst_env *first)
{
    tmp->next = (*env)->next;
    free((*env)->key);
    free((*env)->value);
    free((*env));
    *env = first;
}

void    unset(char *var, t_lst_env **env)
{
    t_lst_env   *tmp;
    t_lst_env   *first;


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
        free(first->value);
        free(first);
    }
    else
        unset2(tmp, env, first);
    index_env_lst(env);
}