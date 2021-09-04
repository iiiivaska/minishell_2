/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghis <eghis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 15:58:55 by eghis             #+#    #+#             */
/*   Updated: 2021/07/16 16:22:40 by eghis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

#define INT_MAX 2147483647

static int	is_space(char ch)
{
	if (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\v' || ch == '\f'
		|| ch == '\r')
		return (1);
	return (0);
}

int	ft_atoi(const char *s)
{
	unsigned long	num;
	int				flag;

	flag = 1;
	num = 0;
	while (is_space(*s))
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			flag *= -1;
		s++;
	}
	while (*s >= 48 && *s <= 57)
	{
		if (num > INT_MAX && flag == 1)
			return (-1);
		if (num > (long)INT_MAX + 1 && flag == -1)
			return (0);
		num = num * 10 + (*s - 48);
		s++;
	}
	return ((int)(num * flag));
}
