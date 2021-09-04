/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghis <eghis@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 14:25:20 by eghis             #+#    #+#             */
/*   Updated: 2021/09/03 16:09:36 by eghis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// считает сколько аргументов
int	ft_arsize(char **args)
{
	int	i;

	i = 0;
	while (args[i] != 0)
		i++;
	return (i);
}

// вывод строки с пробелом
void	ft_putstr_sp(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		ft_putchar(str[i++]);
	ft_putchar(' ');
}

int	ft_echo(char **args)
{
	int	i;
	int	count;
	int	n;

	i = 0;
	n = 0;
	count = ft_arsize(args);
	if (args[1][0] == '-' && args[1][1] == 'n' && args[1][2] == '\0')
	{
		i++;
		n = 1;
	}
	i = 1;
	while (args[i] && ft_strcmp(args[i], "-n") != 0)
	{
		ft_putstr_sp(args[i]);
		i++;
	}
	if (n == 0)
		ft_putchar('\n');
	return (1);
}