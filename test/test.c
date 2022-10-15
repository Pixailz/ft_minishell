/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 04:48:33 by brda-sil          #+#    #+#             */
/*   Updated: 2022/10/02 01:13:11 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* tcsetattr()
 * tcgetattr()
 */
#include <termios.h>

int	g_interrupt_2;

#define BAUDRATE B38400
#define LINE_SIZE 0x100

typedef struct s_main_2
{
	struct termios		term_old;
	struct termios		term_new;
	struct sigaction	sig_act;
	int					std_stream;
	int					termcap;
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
		ioctl(0, TCXONC, TCOON);
		g_interrupt_2 = 1;
	}
}

void	init_signal_2(t_main_2 *config)
{
	sigemptyset(&config->sig_act.sa_mask);
	config->sig_act.sa_handler = signal_handler_2;
	config->sig_act.sa_flags = SA_RESTART;
	config->sig_act.sa_restorer = FT_NULL;
	if (sigaction(SIGINT, &config->sig_act, NULL))
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
		ft_error("get_old_term\n", 2);
	tcsetattr(config->std_stream, TCSANOW, &config->term_new);
}

char	*get_prompt_4(void)
{
	if (g_interrupt_2)
		return (ft_strdup("[1] test> "));
	else
		return (ft_strdup("[0] test> "));
}

void	restore_term(t_main_2 *config)
{
	tcsetattr(config->std_stream, TCSANOW, &config->term_old);
}

void	launch_prompt(void)
{
	char		*line_buffer;
	char		*prompt;

	while (THE_RESPONE_OF_LIFE)
	{
		prompt = get_prompt_4();
		g_interrupt_2 = 0;
		line_buffer = readline(prompt);
		ft_printf("READLINE QUIT\n");
		if (line_buffer == FT_NULL)
			break ;
		else
		{
			ft_printf_fd(LOG_FD, "line_buffer [%s]\n", line_buffer);
			if (g_interrupt_2)
				ft_printf_fd(LOG_FD, "ctrl+c pressed\n");
		}
	}
}

int	main(void)
{
	t_main_2	config;

	init_terminal(&config);
	init_signal_2(&config);
	launch_prompt();
	restore_term(&config);
}
