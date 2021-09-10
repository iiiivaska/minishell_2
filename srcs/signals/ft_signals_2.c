/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signals_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghis <eghis@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 18:15:17 by bsadie            #+#    #+#             */
/*   Updated: 2021/09/10 19:29:38 by eghis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_signothing(int s)
{
	int		a;
	int		b;
	char	*nbr;

	a = 0;
	b = 0;
	nbr = ft_itoa(s);
	if (!g_sig.pid)
	{
		if (!g_sig.dyn)
			ft_signothing_1();
		else
			ft_signothing_2();
	}
	else
	{
		ft_putstr_fd("Quit: ", STDERR);
		ft_putstr_fd(nbr, STDERR);
		ft_putstr_fd("\n", STDERR);
		g_sig.s_quit = 1;
		g_sig.exit_stat = 131;
	}
}

void	ft_signothing_1(void)
{
	int	a;
	int	b;

	b = ft_strlen(rl_line_buffer);
	a = ft_strlen(PROMPT);
	tputs(tgoto(tgetstr("ch", NULL), 0, a + b), 1, ft_putint);
	tputs(tgoto(tgetstr("DC", NULL), 0, 2), 1, ft_putint);
}

void	ft_signothing_2(void)
{
	int	a;
	int	b;

	b = ft_strlen(rl_line_buffer);
	a = ft_strlen("> ");
	tputs(tgoto(tgetstr("ch", NULL), 0, a + b), 1, ft_putint);
	tputs(tgoto(tgetstr("DC", NULL), 0, 2), 1, ft_putint);
}
