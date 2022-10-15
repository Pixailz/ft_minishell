/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_cmds_error.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 20:06:18 by brda-sil          #+#    #+#             */
/*   Updated: 2022/10/03 20:28:16 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	get_error_redir(t_block *tmp, t_main *config)
{
	if (tmp == FT_NULL)
		ft_printf_fd(STDERR_FILENO, \
			"minishell: syntax error near unexpected token `newline'\n");
	else
		ft_printf_fd(STDERR_FILENO, \
			"minishell: syntax error near unexpected token `%s'\n", \
				tmp->block);
	config->interrupt = 5;
}

void	get_error_interrupt(t_main *config)
{
	if (config->interrupt == 5)
	{
		free_config_entry(config);
		exit (0);
	}
	else if (config->interrupt != 0)
	{
		free_config_entry(config);
		exit (130);
	}
}

int	redir_is_good_name(char *file_name)
{
	t_bool	is_good;

	is_good = True;
	if (!ft_strcmp(file_name, "<<"))
		is_good = False;
	else if (!ft_strcmp(file_name, ">>"))
		is_good = False;
	else if (!ft_strcmp(file_name, ">"))
		is_good = False;
	else if (!ft_strcmp(file_name, "<"))
		is_good = False;
	return (is_good);
}
