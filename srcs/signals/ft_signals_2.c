/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signals_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsadie <bsadie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 18:15:17 by bsadie            #+#    #+#             */
/*   Updated: 2021/09/09 18:20:41 by bsadie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

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
