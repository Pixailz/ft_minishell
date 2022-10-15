/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 21:35:42 by stales            #+#    #+#             */
/*   Updated: 2022/07/05 02:50:09 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_print.h"

/**
 * @brief			Write integer nb to the file descriptor fd
 *
 * @param n			Integer to write
 * @param fd		File descriptor
 *
 * @return (size_t)	Number of char written to fd.
 */
size_t	ft_putnbr_fd(int n, int fd)
{
	int	len;

	len = 0;
	if (n > 2147483647)
		return (0);
	if (n == -2147483648)
		return (ft_putstr_fd("-2147483648", fd));
	if (n < 0)
	{
		len += ft_putchar_fd('-', fd);
		n = ~(n - 1);
	}
	if (n >= 10)
		len += ft_putnbr_fd(n / 10, fd);
	len += ft_putchar_fd((n % 10) + '0', fd);
	return (len);
}
