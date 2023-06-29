/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:43:45 by brda-sil          #+#    #+#             */
/*   Updated: 2022/10/14 01:46:59 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_print.h"

int	ft_error(char *msg, int return_code)
{
	if (!errno)
		ft_putendl_fd(msg, 2);
	else
		perror(msg);
	return (return_code);
}
