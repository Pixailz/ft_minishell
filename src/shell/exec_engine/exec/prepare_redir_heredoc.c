/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_redir_heredoc.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 01:20:03 by brda-sil          #+#    #+#             */
/*   Updated: 2022/09/27 23:42:05 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_interrupt;

char	*get_tmp_file(void)
{
	char	*file_name;

	file_name = ft_tmpfile();
	if (ft_isfile(file_name, 0) == 1)
	{
		free(file_name);
		file_name = get_tmp_file();
	}
	return (file_name);
}

void	forked_double_in(t_redirection *double_in, t_main *conf, char **file_n)
{
	char	*buff;
	int		file;

	g_interrupt = 0;
	file = open(*file_n, O_CREAT | O_WRONLY | O_TRUNC, 0000644);
	buff = readline("> ");
	while (buff && ft_strcmp(buff, double_in->content))
	{
		ft_printf_fd(file, "%s\n", buff);
		free(buff);
		buff = readline("> ");
	}
	if (!buff && !g_interrupt)
		ft_printf_fd(STDERR_FILENO, \
			"\nwarning : here-document delimited by EOF(wanted '%s')\n", \
				double_in->content);
	else if (buff)
		free(buff);
	close(file);
	free_config_entry(conf);
	free(*file_n);
	exit(g_interrupt);
}

void	prepare_in_double_file(t_redirection *double_in, t_main *config)
{
	char	*file_name;
	pid_t	forked_heredoc;
	int		status;

	file_name = get_tmp_file();
	set_signal_forked(0);
	forked_heredoc = fork();
	if (!forked_heredoc)
		forked_double_in(double_in, config, &file_name);
	waitpid(forked_heredoc, &status, 0);
	set_signal_base();
	if (WEXITSTATUS(status) == 3)
	{
		config->interrupt = 1;
		ft_printf("\n");
	}
	double_in->file = open(file_name, O_RDONLY);
	dup2(double_in->file, STDIN_FILENO);
	close(double_in->file);
	unlink(file_name);
	free(file_name);
}
