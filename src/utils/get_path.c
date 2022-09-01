/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 01:38:57 by brda-sil          #+#    #+#             */
/*   Updated: 2022/09/01 02:04:59 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_cmd_path(char *name, char **path)
{
	char	*tmp_cmd_path;
	char	*tmp;

	while (*path)
	{
		tmp = ft_strjoin(*path, "/");
		tmp_cmd_path = ft_strjoin(tmp, name);
		free(tmp);
		tmp = NULL;
		if (access(tmp_cmd_path, F_OK | X_OK) == 0)
			return (tmp_cmd_path);
		free(tmp_cmd_path);
		tmp_cmd_path = NULL;
		path++;
	}
	return (NULL);
}

char	**get_path(char **env)
{
	char	*tmp;

	while (ft_strncmp("PATH", *env, 4))
		env++;
	if (!*env)
		return (NULL);
	tmp = *env + 5;
	return (ft_split(tmp, ':'));
}
