/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 03:42:30 by brda-sil          #+#    #+#             */
/*   Updated: 2022/09/28 02:26:43 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_redirection	*redir_new(char *content, int is_double)
{
	t_redirection	*ptr;

	ptr = (t_redirection *)malloc(sizeof(t_redirection));
	if (!ptr)
		return (FT_NULL);
	ptr->content = ft_strdup(content);
	ptr->file = -1;
	ptr->file_name = FT_NULL;
	ptr->is_double = is_double;
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

void	init_redirection_lst(t_redirection **lst, char *content, int is_double)
{
	if (!lst || !*lst)
		*lst = redir_new(content, is_double);
	else
		redir_addback(lst, redir_new(content, is_double));
}

void	init_redirection(t_main *config)
{
	t_block		*tmp;
	size_t		counter;
	t_context	*context;

	tmp = config->line_block;
	context = config->context;
	counter = 0;
	while (tmp)
	{
		if (tmp->block_id == PIPE)
			counter++;
		else if (tmp->block_id == IN_FORWARD)
			init_redirection_lst(&context->cmd[counter]->in_redir, \
				tmp->next->block, 0);
		else if (tmp->block_id == OUT_FORWARD)
			init_redirection_lst(&context->cmd[counter]->out_redir,
				tmp->next->block, 0);
		else if (tmp->block_id == DELIMITER)
			init_redirection_lst(\
				&context->cmd[counter]->in_redir, tmp->next->block, 1);
		else if (tmp->block_id == DBL_OUT_FORWARD)
			init_redirection_lst(\
				&context->cmd[counter]->out_redir, tmp->next->block, 1);
		tmp = tmp->next;
	}
}
