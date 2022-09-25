/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 04:48:33 by brda-sil          #+#    #+#             */
/*   Updated: 2022/09/25 08:31:04 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#include <termios.h>

int	g_has_c;

#define BAUDRATE B38400

typedef struct s_main_2
{
	struct termios		term_old;
	struct termios		term_new;
	struct sigaction	sig_act;
	int					std_stream;
}			t_main_2;

/*############################################################################*/

int	get_stream_tty(void)
{
	if (isatty(STDERR_FILENO))
		return (2);
	else if (isatty(STDOUT_FILENO))
		return (1);
	else if (isatty(STDIN_FILENO))
		return (0);
	return (-1);
}

void	signal_handler_2(int signal)
{
	ft_printf_fd(LOG_FD, "signal catched [%d]\n", signal);
	if (signal == SIGINT)
	{
		ft_printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		g_has_c = 1;
	}
}

void	init_signal_2(t_main_2 *config)
{
	sigemptyset(&config->sig_act.sa_mask);
	config->sig_act.sa_handler = signal_handler_2;
	config->sig_act.sa_flags = 0;
	config->sig_act.sa_restorer = FT_NULL;
	if (sigaction(SIGINT, &config->sig_act, NULL))
		ft_error("init sigaction\n", 4);
	if (sigaction(SIGUSR1, &config->sig_act, NULL))
		ft_error("init sigaction\n", 4);
	if (sigaction(SIGUSR2, &config->sig_act, NULL))
		ft_error("init sigaction\n", 4);
}

void	init_terminal(t_main_2 *config)
{
	config->std_stream = get_stream_tty();
	if (config->std_stream == -1)
		ft_error("no std available\n", 1);
	if (tcgetattr(config->std_stream, &config->term_old))
		ft_error("get_old_term\n", 2);
	if (tcgetattr(config->std_stream, &config->term_new))
		ft_error("get_new_term\n", 3);
	config->term_new.c_iflag = IGNBRK;
	// config->term_new.c_cflag = BRKINT;
	// config->term_new.c_lflag = ISIG;
	config->term_new.c_cc[VINTR] = 1;
	tcsetattr(config->std_stream, TCSANOW, &config->term_new);
}

char	*get_prompt_4(void)
{
	if (g_has_c)
		return (ft_strdup("[1] test> "));
	else
		return (ft_strdup("[0] test> "));
}

void	restore_term(t_main_2 *config)
{
	tcsetattr(config->std_stream, TCSANOW, &config->term_old);
}

int	main(void)
{
	t_main_2	config;
	char		*line_buffer;
	char		*prompt;

	init_terminal(&config);
	init_signal_2(&config);
	while (VRAI)
	{
		g_has_c = 0;
		prompt = get_prompt_4();
		line_buffer = readline(prompt);
		ft_printf_fd(LOG_FD, "line_buffer [%s]\n", line_buffer);
		if (line_buffer == FT_NULL)
			break ;
	}
	restore_term(&config);
}
