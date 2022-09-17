/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 20:06:18 by brda-sil          #+#    #+#             */
/*   Updated: 2022/09/17 22:15:44 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_get_cmd_paths(t_main *config)
{
	int	counter;

	counter = 0;
	while (config->context->cmd[counter])
	{
		config->context->cmd[counter]->path = get_cmd_path(\
			config->context->cmd[counter]->command[0], config->path);
		counter++;
	}
}

size_t	init_cmds_count_args(t_list *tmp)
{
	size_t	nb_args;

	nb_args = 1;
	while (tmp)
	{
		nb_args++;
		tmp = tmp->next;
	}
	return (nb_args);
}

void	init_cmds(t_main *config)
{
	int		counter_1;
	int		counter_2;
	t_list	*tmp;

	counter_1 = 0;
	while (counter_1 < config->context->cmd_nb)
	{
		tmp = config->context->cmd[counter_1]->tmp_command;
		config->context->cmd[counter_1]->command = \
				(char **)malloc(sizeof(char *) * init_cmds_count_args(tmp));
		counter_2 = 0;
		while (tmp)
		{
			config->context->cmd[counter_1]->command[counter_2] = \
				ft_strdup(tmp->content);
			tmp = tmp->next;
			counter_2++;
		}
		config->context->cmd[counter_1]->command[counter_2] = FT_NULL;
		counter_1++;
	}
}

void	prepare_cmds_2(t_cmd *cmd, t_block **tmp, int prev_str)
{
	if (prev_str)
	{
		if (!cmd->tmp_command)
			cmd->tmp_command = ft_lstnew((*tmp)->block);
		else
			ft_lstadd_back(&cmd->tmp_command, ft_lstnew((*tmp)->block));
	}
	*tmp = (*tmp)->next;
}

void	prepare_cmds_1(t_main *config)
{
	t_block	*tmp;
	int		is_prev_str;
	int		cmd_id;

	cmd_id = 0;
	tmp = config->line_block;
	while (tmp)
	{
		is_prev_str = 0;
		if (tmp->block_id == PIPE)
		{
			tmp = tmp->next;
			cmd_id++;
			continue ;
		}
		else if (tmp->block_id != STR)
			tmp = tmp->next;
		else
			is_prev_str = 1;
		prepare_cmds_2(config->context->cmd[cmd_id], &tmp, is_prev_str);
	}
}
