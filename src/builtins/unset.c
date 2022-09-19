#include "minishell.h"

void    unset(char *var, t_lst_env **env)
{
    t_lst_env   *tmp;

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
    free(tmp->key);
        free(tmp->value);
        free(tmp);
}