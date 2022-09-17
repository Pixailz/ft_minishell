/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_redirection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 03:42:30 by brda-sil          #+#    #+#             */
/*   Updated: 2022/09/17 04:44:47 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_redirection	*redir_new(char *content)
{
	t_redirection	*ptr;

	ptr = (t_redirection *)malloc(sizeof(t_redirection));
	if (!ptr)
		return (FT_NULL);
	ptr->content = ft_strdup(content);
	ptr->file = -1;
	ptr->next = FT_NULL;
	return (ptr);
}

void	redir_addback(t_redirection **lst, t_redirection *new)
{
	t_redirection	*ptr;

	if (!lst || !*lst)
		*lst = new;
	ptr = *lst;
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = new;
}

void	init_redirection_lst(t_redirection **lst, char *content)
{
	if (!lst || !*lst)
		*lst = redir_new(content);
	else
		redir_addback(lst, redir_new(content));
}

void	init_redirection(t_main *config)
{
	t_block	*tmp;
	size_t	counter;

	tmp = config->line_block;
	counter = 0;
	while (tmp)
	{
		if (tmp->block_id == PIPE)
			counter++;
		else if (tmp->block_id == IN_FORWARD)
			init_redirection_lst(&config->context->cmd[counter]->in_redir, \
				tmp->next->block);
		else if (tmp->block_id == OUT_FORWARD)
			init_redirection_lst(&config->context->cmd[counter]->out_redir, \
				tmp->next->block);
		else if (tmp->block_id == DELIMITER)
			init_redirection_lst(\
				&config->context->cmd[counter]->double_in_redir, \
					tmp->next->block);
		else if (tmp->block_id == DBL_OUT_FORWARD)
			init_redirection_lst(\
				&config->context->cmd[counter]->double_out_redir, \
					tmp->next->block);
		tmp = tmp->next;
	}
}
