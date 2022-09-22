/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 03:26:51 by brda-sil          #+#    #+#             */
/*   Updated: 2022/09/22 04:23:00 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief			check if path, absolute or not is present
 *
 * @param dir_path	path of the dir to test
 * @note
 *	Needed lib
 *		sys/stat.h
 * @return (int)	0 on success, 1 if not a dir, 2 no such file or dir
 */
int	ft_isdir(char *dir_name)
{
	struct stat	tmp;
	int			error_code;

	error_code = 0;
	if (stat(dir_name, &tmp))
		return (errno);
	if (!S_ISDIR(tmp.st_mode))
		error_code = 1;
	return (error_code);
}
