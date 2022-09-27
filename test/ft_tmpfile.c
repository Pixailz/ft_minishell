/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tmpfile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 13:16:30 by brda-sil          #+#    #+#             */
/*   Updated: 2022/09/27 16:51:59 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_int64	ft_randint(int start, int end)
{
	int				file;
	t_int64			range;
	t_int64			sum;
	t_int64			counter;
	unsigned char	*buff;

	range = end - start + 1;
	if (range < 0)
		return (end + start + 1);
	range = (range / 0xff) + 1;
	file = open("/dev/urandom", O_RDONLY);
	buff = ft_calloc(sizeof(char), range);
	read(file, buff, range);
	close(file);
	sum = 0;
	counter = 0;
	while (counter++ < range)
		sum += buff[counter - 1];
	free(buff);
	return ((sum % (end - start + 1)) + start);
}

#define TMP_RGE "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"

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
	tmp_len = ft_strlen(TMP_RGE) - 1;
	while (counter < 14)
	{
		name[counter++] = TMP_RGE[ft_randint(0, tmp_len)];
	}
	return (name);
}

// int	main(void)
// {
// 	int		counter;
// 	int		max;
// 	char	*name;

// 	counter = 0;
// 	max = 100;
// 	while (counter < max)
// 	{
// 		name = ft_tmpfile();
// 		ft_printf("[%s]\n", name);
// 		free(name);
// 		counter++;
// 	}
// 	return (0);
// }

int	main(void)
{
	int		counter;
	int		max;

	counter = 0;
	max = 10;
	while (counter < max)
	{
		ft_printf("randint [%d]\n", ft_randint(-1, 1));
		counter++;
	}
	return (0);
}
