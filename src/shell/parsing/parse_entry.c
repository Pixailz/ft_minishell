/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_entry.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 00:26:21 by brda-sil          #+#    #+#             */
/*   Updated: 2022/09/20 00:02:31 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parse_cmd(t_main *config)
{
	t_list	*tmp;

	config->line_splitted = ft_better_split(config->line_buffer);
	parse_replace_dollar(config, config->env);
	config->line_block = convert_list(config->line_splitted);
	tmp = config->line_splitted;
	while (tmp)
	{
		tmp = config->line_splitted->next;
		free(config->line_splitted->content);
		config->line_splitted->content = FT_NULL;
		free(config->line_splitted);
		config->line_splitted = tmp;
	}
	get_block(config->line_block);
}
