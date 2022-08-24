/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 21:07:07 by brda-sil          #+#    #+#             */
/*   Updated: 2022/08/24 22:14:15 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	prompt[] = "ecris> ";

void	print_signal(int signal_code)
{
	if (signal_code == SIGQUIT)
	{
		ft_printf("\r");
		ft_printf("%s   ", prompt);
		rl_redisplay();
	}
	if (signal_code == SIGINT)
	{
		ft_printf("%s   \n", prompt);
		rl_on_new_line();
		rl_redisplay();
	}
	ft_printf_fd(2, "SIGNAL (%d) intercepted\n", signal_code);
}

int	main_loop(void)
{
	char	buffer[256];

	signal(SIGINT, print_signal);
	signal(SIGQUIT, print_signal);
	while (VRAI)
	{
		ft_strcpy(buffer, readline(prompt));
		ft_printf_fd(2, buffer);
	}
	return (0);
}
