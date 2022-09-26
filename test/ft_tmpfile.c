/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tmpfile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 13:16:30 by brda-sil          #+#    #+#             */
/*   Updated: 2022/09/26 14:01:32 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_getdiff(int start, int end)
{
	return (end - start);
}

int	ft_randint(int start, int end)
{
	int		file;
	int		range;
	int		sum;
	int		counter;
	char	*buff;

	range = end - start;
	if (range < 0)
		return (end + start + 1);
	range = (range / 0xff) + range % 0xff;
	file = open("/dev/urandom", O_RDONLY);
	buff = ft_calloc(sizeof(char), range);
	read(file, buff, range);
	close(file);
	sum = 0;
	counter = 0;
	while (counter++ < range)
		sum += (unsigned char)buff[counter - 1];
	free(buff);
	return (((sum % (end + (start == 0))) + start));
}

int	main(void)
{
	while (1)
		ft_printf("randint [%d]\n", ft_randint(0, 100000));
	return (0);
}
