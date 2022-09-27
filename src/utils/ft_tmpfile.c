/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tmpfile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 13:16:30 by brda-sil          #+#    #+#             */
/*   Updated: 2022/09/27 21:11:22 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_tmpfile(void)
{
	char	*name;
	int		tmp_len;
	int		counter;

	name = (char *)ft_calloc(sizeof(char), 15);
	counter = 0;
	name[counter++] = 't';
	name[counter++] = 'm';
	name[counter++] = 'p';
	name[counter++] = '.';
	tmp_len = ft_strlen(TMP_RG) - 1;
	while (counter < 14)
	{
		name[counter++] = TMP_RG[ft_randint(0, tmp_len)];
	}
	return (name);
}
