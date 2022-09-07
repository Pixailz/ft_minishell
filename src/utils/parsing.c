/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmailly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 16:31:51 by pmailly           #+#    #+#             */
/*   Updated: 2022/08/31 16:31:53 by pmailly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_better_strjoin(char *s1, char *s2)
{
	t_size  size;
	char    *ptr;

    if (!s1 && !s2)
        return (FT_NULL);
    else if (s1 && !s2)
        return (s1);
    else if (!s1 && s2)
    {
        return (s2);
    }
    size = ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1;
	ptr = ft_calloc(0b1, size + 0b1);
	if (!ptr)
		return (FT_NULL);
	ptr[size] = 0;
	ft_strcpy(ptr, (char *)s1);
	ft_strcat(ptr, (char *)s2);
    free(s1);
    free(s2);
	return (ptr);
}

char    *find_key(char **input, t_lst_env *env)
{
    char    *key;
    int     i;

    i = 0;
    if (**input != '$')
        return(ft_strdup("\0"));
    (*input)++;
    while ((*input)[i] && (ft_isalnum((*input)[i]) || (*input)[i] == '_'))
        i++;
    if (i == 0)
        return (ft_strdup("$"));
    key = ft_substr(*input, 0, i);
    while (env)
    {
        if (!ft_strcmp_env(key, env->key))
            break ;
        env = env->next;
    }
    while (--i >= 0)
        (*input)++;
    free(key);
    if (env)
        return (ft_strdup(env->value));
    return(ft_strdup("\0"));
}

char    *replace_key(char *input, t_lst_env *env)
{
    int     i;
    char    *str;

    i = 0;
    if (!input || ft_strcchr(" '|<>", input[0]))
        return (ft_strdup(input));
    str = ft_strdup("\0");
    while (input[i])
    {
        while (input[i] && input[i] != '$')
            i++;
        str = ft_better_strjoin(str, ft_substr(input, 0, i));
        while (i > 0)
        {
            i--;
            input++;
        }
        str = ft_better_strjoin(str, find_key(&input, env));
    }
    return (str);
}

void    process_replace_dollar(t_list **input, t_lst_env *env)
{
    char    *str;
    t_list  *tmp;
    t_lst_env  *tmp2;

    tmp = *input;
    while (tmp)
    {
        str = replace_key(tmp->content, env);
        free(tmp->content);
        tmp->content = str;
        tmp = tmp->next;
    }
    tmp2 = env->next;
    while (env)
    {
        free(env->key);
        free(env->value);
        free(env);
        env = tmp2;
        if (tmp2)
            tmp2 = tmp2->next;
    }
}