/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_status_prompt.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 00:14:52 by brda-sil          #+#    #+#             */
/*   Updated: 2022/10/02 01:58:36 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_status_prompt_color(t_main *config)
{
	int	error_color;

	error_color = 0;
	if (config->last_return_value == 130)
		error_color = 2;
	else if (!config->last_return_value)
		error_color = 1;
	return (error_color);
}

void	get_status_prompt_fill_array(int ret_val, char **tmp_2, char *tmp_1)
{
	if (ret_val >= 0 && ret_val <= 9)
	{
		(*tmp_2)[0] = ' ';
		(*tmp_2)[1] = tmp_1[0];
		(*tmp_2)[2] = ' ';
	}
	else if (ret_val >= 10 && ret_val <= 99)
	{
		(*tmp_2)[0] = ' ';
		(*tmp_2)[1] = tmp_1[0];
		(*tmp_2)[2] = tmp_1[1];
	}
	else
	{
		(*tmp_2)[0] = tmp_1[0];
		(*tmp_2)[1] = tmp_1[1];
		(*tmp_2)[2] = tmp_1[2];
	}
}

char	*get_status_prompt_array(t_main *config)
{
	char	*tmp_1;
	char	*tmp_2;

	tmp_2 = (char *)ft_calloc(sizeof(char), 4);
	if (!tmp_2)
		return (FT_NULL);
	tmp_1 = ft_itoa(config->last_return_value);
	get_status_prompt_fill_array(config->last_return_value, &tmp_2, tmp_1);
	free(tmp_1);
	return (tmp_2);
}

char	*get_status_prompt_assemble(int status_code, char **array)
{
	char	*tmp_1;
	char	*tmp_2;

	if (status_code == 1)
		tmp_1 = ft_strjoin("[", C_PROMPT_STATUS_1);
	else if (status_code == 2)
		tmp_1 = ft_strjoin("[", C_PROMPT_STATUS_2);
	else
		tmp_1 = ft_strjoin("[", C_PROMPT_STATUS_0);
	tmp_2 = ft_strjoin(tmp_1, *array);
	free(tmp_1);
	free(*array);
	tmp_1 = ft_strjoin(tmp_2, C_RESET);
	free(tmp_2);
	tmp_2 = ft_strjoin(tmp_1, "]");
	free(tmp_1);
	return (tmp_2);
}

char	*get_status_prompt(t_main *config)
{
	char	*status;
	char	*array;

	array = get_status_prompt_array(config);
	status = get_status_prompt_assemble(\
		get_status_prompt_color(config), \
		&array);
	return (status);
}
