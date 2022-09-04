/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 16:10:10 by brda-sil          #+#    #+#             */
/*   Updated: 2022/09/02 22:25:27 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

void	push_string(char **str, int n)
{
	int	counter;

	counter = 0;
	while (counter < n)
	{
		(*str)++;
		counter++;
	}
}

int	main(void)
{
	char	*test;

	test = strdup("this is a test");
	printf("%s\n", test);
	push_string(&test, 3);
	printf("%s\n", test);
}
