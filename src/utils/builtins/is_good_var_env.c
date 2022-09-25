/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_good_var_env.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 15:39:45 by brda-sil          #+#    #+#             */
/*   Updated: 2022/09/25 00:13:01 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_good_var_env_first(char c)
{
	if (c == '_')
		return (True);
	if (ft_isdigit(c))
		return (False);
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (True);
	return (False);
}

int	is_good_var_env_char(char c)
{
	if (c == '_')
		return (True);
	if (ft_isdigit(c))
		return (True);
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (True);
	return (False);
}

int	is_good_var_env(char *str)
{
	int	counter;
	int	len;

	counter = 0;
	len = ft_strlen(str);
	if (counter == 0 && is_good_var_env_first(str[counter]))
		counter++;
	else
	{
		ft_printf_fd(LOG_FD, "bad first character\n");
		return (0);
	}
	while (counter < len)
	{
		if (str[counter] == '=')
			break ;
		if (!is_good_var_env_char(str[counter]))
			return (0);
		counter++;
	}
	if (str[counter] == '=')
	{
		ft_printf_fd(LOG_FD, "str[counter] == '='\n");
		return (1);
	}
	else if (len == counter)
	{
		ft_printf_fd(LOG_FD, "len == counter\n");
		return (1);
	}
	return (0);
}