/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 10:33:10 by brda-sil          #+#    #+#             */
/*   Updated: 2022/09/20 10:51:32 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtin_pwd(t_cmd *cmd)
{
	char	*buff;

	do_something_with_cmd(cmd);
	buff = get_cwd();
	ft_printf("%s\n", buff);
	free(buff);
	return (0);
}
