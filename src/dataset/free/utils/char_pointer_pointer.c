/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_pointer_pointer.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 00:16:33 by brda-sil          #+#    #+#             */
/*   Updated: 2022/09/19 00:39:48 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_char_pointer_pointer(char **str)
{
	int	counter;

	counter = 0;
	while (str[counter])
	{
		free(str[counter]);
		str[counter] = FT_NULL;
		counter++;
	}
	free(str);
	str = FT_NULL;
}
