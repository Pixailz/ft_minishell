/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 00:53:56 by brda-sil          #+#    #+#             */
/*   Updated: 2022/09/19 00:37:24 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_env(t_lst_env *envlst)
{
	while (envlst != FT_NULL)
	{
		if (envlst && envlst->value)
			printf("%s%s\n", (char *)envlst->key, (char *)envlst->value);
		else
			printf("%s\n", (char *)envlst->key);
		envlst = envlst->next;
	}
}
