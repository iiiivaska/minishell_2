/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signals.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghis <eghis@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 18:34:13 by eghis             #+#    #+#             */
/*   Updated: 2021/09/10 19:29:35 by eghis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	init_signals(void)
{
	signal(SIGQUIT, &ft_signothing);
	signal(SIGINT, &ft_sigint);
	g_sig.s_int = 0;
	g_sig.s_quit = 0;
	g_sig.pid = 0;
	g_sig.ch = 0;
	g_sig.dyn = 0;
}

void	init_signals_2(void)
{
	signal(SIGQUIT, &ft_signothing);
	signal(SIGINT, &ft_sigint);
	g_sig.s_int = 0;
	g_sig.s_quit = 0;
	g_sig.pid = 0;
	g_sig.ch = g_sig.ch;
	g_sig.dyn = 0;
}

void	sig_int_1(void)
{
	char	*buffer;

	buffer = (char *)(malloc(sizeof(char) * (ft_strlen(rl_line_buffer) + 1)));
	if (!buffer)
		ft_exit(0, strerror(errno));
	ft_strlcpy(buffer, rl_line_buffer, ft_strlen(rl_line_buffer) + 1);
	write(1, PROMPT, ft_strlen(PROMPT));
	write(1, buffer, ft_strlen(buffer));
	write(1, "  \n", 3);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	free(buffer);
}

void	sig_int_2(void)
{
	char	*buffer;

	buffer = (char *)(malloc(sizeof(char) * (ft_strlen(rl_line_buffer) + 1)));
	if (!buffer)
		ft_exit(0, strerror(errno));
	ft_strlcpy(buffer, rl_line_buffer, ft_strlen(rl_line_buffer) + 1);
	write(1, "> ", 2);
	write(1, buffer, ft_strlen(buffer));
	write(1, "  \n", 3);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	free(buffer);
	g_sig.s_int = 1;
}

void	ft_sigint(int s)
{
	s = s + 0;
	if (!g_sig.pid)
	{
		if (!g_sig.dyn)
		{
			sig_int_1();
		}
		else
		{
			sig_int_2();
		}
		g_sig.exit_stat = 1;
	}
	else
	{
		ft_putstr_fd("\n", 1);
		g_sig.exit_stat = 130;
	}
	g_sig.s_int = 1;
}
