/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 00:53:56 by brda-sil          #+#    #+#             */
/*   Updated: 2022/09/22 06:55:02 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtin_env(t_lst_env *envlst)
{
	while (envlst != FT_NULL)
	{
		if (envlst && envlst->value)
			printf("%s%s\n", (char *)envlst->key, (char *)envlst->value);
		envlst = envlst->next;
	}
	return (0);
}
