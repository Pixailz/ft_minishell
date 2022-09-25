/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_prompt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 06:19:35 by brda-sil          #+#    #+#             */
/*   Updated: 2022/09/25 07:05:04 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	get_prompt_init_cwd(t_main *config)
{
	static int	has_malloc_cwd = 0;

	if (has_malloc_cwd)
		free(config->cwd);
	config->cwd = get_env("PWD", config->env);
	if (config->cwd == FT_NULL)
	{
		config->cwd = get_cwd();
		has_malloc_cwd = 1;
	}
	config->home = get_env("HOME", config->env);
}

int	get_prompt_init(t_main *config)
{
	int			error_code;

	error_code = 0;
	get_prompt_init_cwd(config);
	if (ft_isdir(config->home, 0) != 1)
		error_code = 1;
	else if (ft_strncmp(config->cwd, config->home, ft_strlen(config->home)))
		error_code = 1;
	else if (ft_strlen(config->home) == 1 && config->home[0] == '/')
		error_code = 1;
	return (error_code);
}
