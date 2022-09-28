/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_redir_heredoc.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 01:20:03 by brda-sil          #+#    #+#             */
/*   Updated: 2022/09/28 03:29:14 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_interrupt;

char	*get_tmp_file(void)
{
	char	*file_name;

	file_name = ft_tmpfile(1);
	if (ft_isfile(file_name, 0) == 1)
	{
		free(file_name);
		file_name = get_tmp_file();
	}
	return (file_name);
}

void	forked_double_in(t_redirection *double_in, t_main *conf)
{
	char	*buff;
	int		file;

	g_interrupt = 0;
	file = open(double_in->file_name, O_CREAT | O_WRONLY | O_TRUNC, 0000644);
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
	exit(g_interrupt);
}

void	prepare_in_double_file(t_redirection *double_in, t_main *config)
{
	pid_t	forked_heredoc;
	int		status;

	double_in->file_name = get_tmp_file();
	set_signal_forked(0);
	forked_heredoc = fork();
	if (!forked_heredoc)
		forked_double_in(double_in, config);
	waitpid(forked_heredoc, &status, 0);
	if (WEXITSTATUS(status) == 3)
	{
		config->interrupt = 1;
		ft_printf("\n");
	}
	set_signal_base();
}
