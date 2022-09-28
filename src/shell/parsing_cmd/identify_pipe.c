/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identify_pipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 01:19:00 by brda-sil          #+#    #+#             */
/*   Updated: 2022/09/24 19:41:43 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_out_forward(t_block *input)
{
	if (input->block[0] == '>')
	{
		if (ft_strlen(input->block) == 2)
			input->block_id = DBL_OUT_FORWARD;
		else if (ft_strlen(input->block) == 1)
			input->block_id = OUT_FORWARD;
		else
			input->block_id = ERROR;
		return (1);
	}
	return (0);
}

int	is_in_forward(t_block *input)
{
	if (input->block[0] == '<')
	{
		if (ft_strlen(input->block) == 2)
			input->block_id = DELIMITER;
		else if (ft_strlen(input->block) == 1)
			input->block_id = IN_FORWARD;
		else
			input->block_id = ERROR;
		return (1);
	}
	return (0);
}

int	is_pipe(t_block *input)
{
	if (input->block[0] == '|')
	{
		if (ft_strlen(input->block) == 1)
			input->block_id = PIPE;
		else
			input->block_id = ERROR;
		return (1);
	}
	return (0);
}

void	identify_redirection(t_block *input)
{
	while (input)
	{
		if (is_pipe(input))
			input = input->next;
		else if (is_in_forward(input))
			input = input->next;
		else if (is_out_forward(input))
			input = input->next;
		else if (!ft_strchr(" <>|", input->block[0]))
			input = input->next;
		else if (input->block[0] == ' ')
		{
			input->block_id = SPACEE;
			input = input->next;
		}
		else
			input = input->next;
	}
	return ;
}
