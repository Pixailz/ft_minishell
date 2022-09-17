/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_prepare_redirection.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 01:20:03 by brda-sil          #+#    #+#             */
/*   Updated: 2022/09/17 05:47:57 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_prepare_in_file(t_context *config)
{
	t_redirection	*tmp;

	tmp = config->cmd[config->cmd_id]->in_redir;
	while (tmp)
	{
		tmp->file = open(tmp->content, O_RDONLY);
		if (tmp->file > -1)
			dup2(tmp->file, STDIN_FILENO);
		else
		{
			ft_printf_fd(STDERR_FILENO, \
				"minishell: %s: No such file or directory\n", \
					tmp->content);
			free_exec_entry(config);
			exit(1);
		}
		close(tmp->file);
		tmp = tmp->next;
	}
}

void	exec_prepare_in_double_file(t_context *config)
{
	t_redirection	*tmp;
	char			*buf;
	int				file;

	tmp = config->cmd[config->cmd_id]->double_in_redir;
	file = open(".heredoc_tmp", O_CREAT | O_WRONLY | O_TRUNC, 0000644);
	while (VRAI)
	{
		ft_printf_fd(1, "> ");
		buf = ft_get_next_line(1);
		if (!buf)
			exit(1);
		if (buf[ft_strlen(tmp->content)] == '\n' && \
		!ft_strncmp(tmp->content, buf, ft_strlen(tmp->content)))
			break ;
		write(file, buf, ft_strlen(buf) - 1);
		write(file, "\n", 1);
		free(buf);
	}
	free(buf);
	close(file);
	file = open(".heredoc_tmp", O_RDONLY);
	dup2(file, STDIN_FILENO);
}

void	exec_prepare_out_file(t_context *config)
{
	t_redirection	*tmp;

	tmp = config->cmd[config->cmd_id]->out_redir;
	while (tmp)
	{
		tmp->file = open(tmp->content, O_CREAT | O_RDWR | O_TRUNC, 0000664);
		if (tmp->file > -1)
			dup2(tmp->file, STDOUT_FILENO);
		else
		{
			ft_printf_fd(STDERR_FILENO, \
				"minishell: %s: Permission denied\n", tmp->content);
			free_exec_entry(config);
			exit(1);
		}
		close(tmp->file);
		tmp = tmp->next;
	}
}

void	exec_prepare_out_double_file(t_context *config)
{
	t_redirection	*tmp;

	tmp = config->cmd[config->cmd_id]->double_out_redir;
	while (tmp)
	{
		tmp->file = open(tmp->content, O_WRONLY | O_CREAT | O_APPEND, 0000664);
		if (tmp->file > -1)
			dup2(tmp->file, STDOUT_FILENO);
		else
		{
			ft_printf_fd(STDERR_FILENO, \
				"minishell: %s: Permission denied\n", tmp->content);
			free_exec_entry(config);
			exit(1);
		}
		close(tmp->file);
		tmp = tmp->next;
	}
}

void	exec_prepare_redirection(t_context *config)
{
	t_cmd	*cmd;

	cmd = config->cmd[config->cmd_id];
	if (cmd->in_redir)
		exec_prepare_in_file(config);
	if (cmd->double_in_redir)
		exec_prepare_in_double_file(config);
	if (cmd->out_redir)
		exec_prepare_out_file(config);
	if (cmd->double_out_redir)
		exec_prepare_out_double_file(config);
}
