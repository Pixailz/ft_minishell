/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_better_split.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 00:03:22 by brda-sil          #+#    #+#             */
/*   Updated: 2022/08/30 13:12:11 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_better_split(const char *s, char delim, const char *encl)
{
	int		tab_len;
	char	*encl_ptr;
	char	*s_ptr;

	if (!s)
		return (NULL);
	tab_len = ft_better_get_words(s, delim, encl);
	ft_printf("%s -> tab_len -> %d\n", s, tab_len);
	return ((char **)0);
}
