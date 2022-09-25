/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_redir_heredoc.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 01:20:03 by brda-sil          #+#    #+#             */
/*   Updated: 2022/09/25 08:15:12 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	prepare_in_double_file_join(t_list *buf_lst)
{
	t_list	*tmp;
	int		file_in;
	int		file_out;

	tmp = buf_lst;
	file_in = open(".here_doc", O_CREAT | O_WRONLY, 0000644);
	while (tmp)
	{
		write(file_in, tmp->content, ft_strlen(tmp->content));
		tmp = tmp->next;
	}
	close(file_in);
	file_out = open(".here_doc", O_RDONLY);
	dup2(file_out, STDIN_FILENO);
	close(file_out);
	unlink(".here_doc");
	free_t_list(buf_lst);
}

void	prepare_in_double_file(t_redirection *double_in)
{
	char	*buf;
	t_list	*buf_lst;

	buf_lst = FT_NULL;
	while (VRAI)
	{
		ft_printf_fd(1, "> ");
		buf = ft_get_next_line(1);
		if (!buf)
			exit(1);
		if (buf[ft_strlen(double_in->content)] == '\n' && \
		!ft_strncmp(double_in->content, buf, ft_strlen(double_in->content)))
			break ;
		if (buf_lst == FT_NULL)
			buf_lst = ft_lstnew(buf);
		else
			ft_lstadd_back(&buf_lst, ft_lstnew(buf));
	}
	free(buf);
	prepare_in_double_file_join(buf_lst);
}
