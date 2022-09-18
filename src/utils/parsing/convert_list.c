/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 01:13:53 by brda-sil          #+#    #+#             */
/*   Updated: 2022/09/17 02:36:50 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_block	*convert_list(t_list *input)
{
	t_block	*new_input;

	new_input = FT_NULL;
	while (input)
	{
		ft_lstadd_back_block(&new_input, ft_lstnew_block(input->content));
		input = input->next;
	}
	return (new_input);
}
