/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_entry.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 00:26:21 by brda-sil          #+#    #+#             */
/*   Updated: 2022/09/17 01:48:15 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parse_cmd_entry(t_main *config)
{
	config->line_splitted = ft_better_split(config->line_buffer);
	parse_replace_dollar(config, config->env);
	config->line_block = convert_list(config->line_splitted);
	get_block(config->line_block);
}
