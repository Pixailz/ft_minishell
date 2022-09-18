/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_redirection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 01:20:03 by brda-sil          #+#    #+#             */
/*   Updated: 2022/09/18 23:04:50 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	prepare_in_file(t_redirection *in_file, t_context *context)
{
	in_file->file = open(in_file->content, O_RDONLY);
	if (in_file->file > -1)
		dup2(in_file->file, STDIN_FILENO);
	else
	{
		ft_printf_fd(STDERR_FILENO, \
			"minishell: %s: No such file or directory\n", \
				in_file->content);
		free_exec_entry(context);
		exit(1);
	}
	close(in_file->file);
}

void	prepare_in_double_file(t_redirection *double_in, t_context *context)
{
	char			*buf;
	int				file;

	double_in->file = open(".heredoc_tmp", O_CREAT | O_WRONLY | O_TRUNC, \
						0000644);
	while (VRAI)
	{
		ft_printf_fd(1, "> ");
		buf = ft_get_next_line(1);
		if (!buf)
			exit(1);
		if (buf[ft_strlen(double_in->content)] == '\n' && \
		!ft_strncmp(double_in->content, buf, ft_strlen(double_in->content)))
			break ;
		write(double_in->file, buf, ft_strlen(buf) - 1);
		write(double_in->file, "\n", 1);
		free(buf);
	}
	free(buf);
	close(double_in->file);
	double_in->file = open(".heredoc_tmp", O_RDONLY);
	dup2(double_in->file, STDIN_FILENO);
	close(double_in->file);
}

void	prepare_out_file(t_redirection *out, t_context *context)
{
	out->file = open(out->content, O_CREAT | O_RDWR | O_TRUNC, 0000644);
	if (out->file > -1)
		dup2(out->file, STDOUT_FILENO);
	else
	{
		ft_printf_fd(STDERR_FILENO, \
			"minishell: %s: Permission denied\n", out->content);
		free_exec_entry(context);
		exit(1);
	}
	close(out->file);
}

void	prepare_out_double_file(t_redirection *double_out, t_context *context)
{
	double_out->file = open(double_out->content, \
							O_WRONLY | O_CREAT | O_APPEND, 0000644);
	if (double_out->file > -1)
		dup2(double_out->file, STDOUT_FILENO);
	else
	{
		ft_printf_fd(STDERR_FILENO, \
			"minishell: %s: Permission denied\n", double_out->content);
		free_exec_entry(context);
		exit(1);
	}
	close(double_out->file);
}

void	prepare_redirection(t_context *context)
{
	t_cmd	*cmd;

	cmd = context->cmd[context->cmd_id];
	if (cmd->out_redir)
		prepare_out_file_ng(context);
	if (cmd->in_redir)
		prepare_in_file_ng(context);
}
