/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 03:22:16 by pmailly           #+#    #+#             */
/*   Updated: 2022/09/01 04:06:41 by brda-sil         ###   ########.fr       */
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

static void	unlink_key_value(char *var_env, char **key, char **value)
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

static t_lst_env	*ft_lstnew_env(void *env)
{
	t_lst_env	*ptr;

	ptr = (t_lst_env *)malloc(sizeof(t_lst_env));
	if (!ptr)
		return (FT_NULL);
	ptr->index = 0;
	unlink_key_value(env, (char **)&ptr->key, (char **)&ptr->value);
	ptr->next = FT_NULL;
	return (ptr);
}

int	ft_strcmp_env(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2 && *s1 != '=' && *s2 != '=')
	{
		s2++;
		s1++;
	}
	if (*s1 == '=' && *s2 != '=')
		return (-1);
	else if (*s2 == '=' && *s1 != '=')
		return (1);
	else
		return ((unsigned char)*s1 - (unsigned char)*s2);
}

static void	index_env_lst2(t_lst_env *lst, t_lst_env **tmp, t_lst_env **tmp2, int *i)
{
	*tmp2 = lst->next;
	while ((*tmp2)->next)
	{
		*tmp2 = (*tmp2)->next;
		if ((*tmp2)->index == 0 && ft_strcmp_env((*tmp)->key, (*tmp2)->key) > 0)
			*tmp = *tmp2;
	}
	(*tmp)->index = *i;
	(*i)++;
	*tmp = lst;
}

void	index_env_lst(t_lst_env **envlst)
{
	t_lst_env	*tmp;
	t_lst_env	*tmp2;
	int			i;
	int			len;

	i = 1;
	len = 0;
	tmp = *envlst;
	while (tmp)
	{
		len++;
		tmp = tmp->next;
	}
	tmp = *envlst;
	while (i <= len)
	{
		while (tmp->index != 0)
		{
			tmp = tmp->next;
			if (tmp == NULL)
				return ;
		}
		index_env_lst2(*envlst, &tmp, &tmp2, &i);
		tmp = *envlst;
	}
	return ;
}

void    print_env(t_lst_env *envlst)
{
    while (envlst != NULL)
    {
        if (envlst && envlst->value)
            printf("%s%s\n", (char *)envlst->key, (char *)envlst->value);
        else
            printf("%s\n", (char *)envlst->key);
        envlst = envlst->next;
    }
}

void    print_export(t_lst_env *envlst)
{
    t_lst_env   *tmp;
    int         i;

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

void    export_var_to_env(t_lst_env **envlst, char *var)
{
    t_lst_env   *tmp;
    int         i;

    i = 1;
    tmp = *envlst;
    while (tmp != NULL)
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
    while (tmp != NULL)
    {
        tmp-> index = 0;
        tmp = tmp->next;
    }
    index_env_lst(envlst);
}

t_lst_env  *env_to_lst(char **env)
{
    t_lst_env    *envlst;
    int         i;

    i = -1;
    envlst = NULL;
    while (env[++i] != NULL)
        ft_lstadd_back_env(&envlst, ft_lstnew_env(env[i]));
    index_env_lst(&envlst);
    return (envlst);
    // print_env(envlst);
    // print_export(envlst);
    // export_var_to_env(&envlst, "SALUT=salut");
    // print_env(envlst);
    // print_export(envlst);
    // while (envlst != NULL)
    // {
    //     printf("%d %s%s\n", envlst->index, (char *)envlst->key, (char *)envlst->value);
    //     envlst = envlst->next;
    // }
    // tmp = envlst;
    // while (tmp != NULL)
    // {
    //     tmp = envlst;
    //     while (tmp && tmp->index != i)
    //         tmp = tmp->next;
    //     if (tmp && tmp->value)
    //         printf("declare -x %s\"%s\"\n", (char *)tmp->key, (char *)tmp->value);
    //     else if (tmp && tmp->value)
    //         printf("declare -x %s\n", (char *)tmp->key);
    //     i++;
    // }
}
