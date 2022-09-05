/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 03:52:38 by brda-sil          #+#    #+#             */
/*   Updated: 2022/09/04 19:21:47 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>

pid_t	do_command_begin(char *path, char **cmd, int *end)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		dup2(end[1], 1);
		dup2(end[0], 0);
		execve(path, cmd, NULL);
	}
	close(end[1]);
	return (pid);
}

pid_t	do_command_between(char *path, char **cmd, int *end1, int *end2)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		dup2(end1[0], 0);
		dup2(end2[1], 1);
		close(end2[0]);
		execve(path, cmd, NULL);
	}
	close(end1[0]);
	close(end2[1]);
	return (pid);
}

pid_t	do_command_end(char *path, char **cmd, int *end)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		dup2(end[0], 0);
		dup2(end[1], 1);
		execve(path, cmd, NULL);
	}
	close(end[0]);
	return (pid);
}

int	main(void)
{
	pid_t	pid[4];
	int		end[3][2];
	char	*cmd1[] = {"echo", "test1", NULL};
	char	*cmd2[] = {"cat", "-e", NULL};
	char	*cmd3[] = {"cat", "-e", NULL};
	char	*cmd4[] = {"cat", "-e", NULL};

	pipe(end[0]);
	pipe(end[1]);
	pipe(end[2]);
	pid[0] = do_command_begin("/usr/bin/echo", cmd1, end[0]);
	pid[1] = do_command_between("/usr/bin/cat", cmd2, end[0], end[1]);
	pid[2] = do_command_between("/usr/bin/cat", cmd3, end[1], end[2]);
	pid[3] = do_command_end("/usr/bin/cat", cmd4, end[2]);
	close(end[0][0]);
	close(end[0][1]);
	close(end[1][0]);
	close(end[1][1]);
	close(end[2][0]);
	close(end[2][1]);
	waitpid(pid[0], NULL, 0);
	waitpid(pid[1], NULL, 0);
	waitpid(pid[2], NULL, 0);
	waitpid(pid[3], NULL, 0);
}
