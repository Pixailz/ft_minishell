/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_context.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 07:32:18 by brda-sil          #+#    #+#             */
/*   Updated: 2022/09/18 23:31:59 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	get_number_of_command(t_main *config)
{
	size_t	nb_cmd;
	t_block	*tmp;

	tmp = config->line_block;
	nb_cmd = 1;
	while (tmp)
	{
		if (tmp->block_id == PIPE)
			nb_cmd++;
		tmp = tmp->next;
	}
	return (nb_cmd);
}

int	init_context(t_main *config)
{
	int	counter;

	config->context = (t_context *)malloc(sizeof(t_context));
	if (!config->context)
		return (1);
	config->context->cmd_nb = get_number_of_command(config);
	config->context->cmd_id = 0;
	config->context->pipe_id = 0;
	config->context->default_in = dup(0);
	config->context->default_out = dup(1);
	config->context->pipes = malloc(sizeof(int *) * \
												(config->context->cmd_nb - 1));
	config->context->path = ft_split(get_path_from_env(config->env), ':');
	if (!config->context->pipes)
		return (2);
	counter = 0;
	while (counter < config->context->cmd_nb - 1)
	{
		config->context->pipes[counter] = malloc(sizeof(int) * 2);
		if (!config->context->pipes[counter])
			return (3);
		pipe(config->context->pipes[counter]);
		counter++;
	}
	return (0);
}

int	init_cmd(t_main *config)
{
	int	counter;

	config->context->cmd = (t_cmd **)malloc(sizeof(t_cmd *) * \
													config->context->cmd_nb);
	if (!config->context->cmd)
		return (4);
	counter = 0;
	while (counter < config->context->cmd_nb)
	{
		config->context->cmd[counter] = (t_cmd *)malloc(sizeof(t_cmd));
		if (!config->context->cmd[counter])
			return (5);
		config->context->cmd[counter]->return_value = 0;
		config->context->cmd[counter]->in_redir = FT_NULL;
		config->context->cmd[counter]->out_redir = FT_NULL;
		config->context->cmd[counter]->tmp_command = FT_NULL;
		counter++;
	}
	return (0);
}

int	init_context_entry(t_main *config)
{
	int	return_code;

	return_code = init_context(config);
	if (return_code)
		return (return_code);
	return_code = init_cmd(config);
	if (return_code)
		return (return_code);
	return (0);
}
