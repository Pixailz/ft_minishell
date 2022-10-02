/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
<<<<<<<< HEAD:libft/src/check/ft_isgoodi.c
/*   ft_isgoodi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 01:06:36 by brda-sil          #+#    #+#             */
/*   Updated: 2022/10/01 18:39:11 by brda-sil         ###   ########.fr       */
========
/*   ft_iscdable.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 17:13:57 by brda-sil          #+#    #+#             */
/*   Updated: 2022/09/28 17:21:14 by brda-sil         ###   ########.fr       */
>>>>>>>> rendu:src/utils/ft_iscdable.c
/*                                                                            */
/* ************************************************************************** */

#include "libft_check.h"

<<<<<<<< HEAD:libft/src/check/ft_isgoodi.c
t_bool	ft_isgoodi(int n, int neg)
{
	t_bool	is_good;

	is_good = True;
	if (neg == 1)
	{
		if (n > INT_MAX || n < 0)
			is_good = False;
	}
	else
	{
		if ((n * neg) < INT_MIN || (n * neg) > 0)
			is_good = False;
	}
	return (is_good);
========
t_bool	ft_iscdable(char *dir_name)
{
	int	uid;
	int	gid;
	int	uid_dir;
	int	gid_dir;

	uid = ft_getuid();
	gid = ft_getgid();
	uid_dir = ft_getuid_dir(dir_name);
	gid_dir = ft_getgid_dir(dir_name);
	if (uid == uid_dir)
	{
		if (ft_isdir(dir_name, S_IXUSR) == 1)
			return (True);
		else
			return (False);
	}
	if (gid == gid_dir)
		if (ft_isdir(dir_name, S_IXGRP) == 1)
			return (True);
	if (ft_isdir(dir_name, S_IXOTH) == 1)
		return (True);
	return (False);
>>>>>>>> rendu:src/utils/ft_iscdable.c
}
