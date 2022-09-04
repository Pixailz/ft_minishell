/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 03:52:38 by brda-sil          #+#    #+#             */
/*   Updated: 2022/09/04 05:10:33 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>

int	main(void)
{
	pid_t	pid[2];
	int		end[2];
	char	*cmd1[] = {"echoo", "test1", NULL};
	char	*cmd2[] = {"echo", "'test2'", NULL};
	// char	*cmd2[] = {"cat", "-e", NULL};
	int		state[2];

	pipe(end);
	pid[0] = fork();
	if (pid[0] == 0)
	{
		dup2(end[1], 1);
		close(0);
		execve("/usr/bin/echoo", cmd1, NULL);
	}
	else
	{
		pid[1] = fork();
		if (pid[1] == 0)
		{
			dup2(end[0], 0);
			execve("/usr/bin/echo", cmd2, NULL);
		}
		else
		{
			waitpid(pid[0], NULL, WNOHANG);
			waitpid(pid[1], NULL, WNOHANG);
		}
	}
	return (0);
}
