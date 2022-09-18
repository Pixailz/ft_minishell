/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_block.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 01:16:02 by brda-sil          #+#    #+#             */
/*   Updated: 2022/09/17 02:09:33 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_block	*ft_lstnew_block(void *content)
{
	t_block	*ptr;

	ptr = (t_block *)malloc(sizeof(t_block));
	if (!ptr)
		return (FT_NULL);
	ptr->block_id = STR;
	ptr->block = ft_strdup(content);
	ptr->next = FT_NULL;
	return (ptr);
}

t_block	*ft_lstadd_back_block(t_block **lst, t_block *new)
{
	t_block	*ptr;

	if (!lst || !*lst)
	{
		*lst = new;
		return (*lst);
	}
	ptr = *lst;
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = new;
	return (ptr->next);
}

void	join_all(t_block *input)
{
	t_block	*tmp;
	char	*str;

	while (input)
	{
		tmp = input->next;
		if (tmp && !input->block_id && !tmp->block_id)
		{
			str = ft_strjoin(input->block, tmp->block);
			free(input->block);
			input->block = str;
			input->next = tmp->next;
			free(tmp->block);
			free(tmp);
		}
		else if (tmp && tmp->block_id == SPACEE)
		{
			input->next = tmp->next;
			input = input->next;
			free(tmp->block);
			free(tmp);
		}
		else
			input = input->next;
	}
}

void	trim_quotes(t_block *input)
{
	char	*tmp;

	while (input)
	{
		if (input->block[0] == '"' || input->block[0] == '\'')
		{
			tmp = input->block;
			input->block++;
			input->block = ft_substr(input->block, 0, \
												ft_strlen(input->block) - 1);
			free(tmp);
		}
		input = input->next;
	}
}

void	get_block(t_block *input)
{
	identify_redirection(input);
	trim_quotes(input);
	join_all(input);
}
