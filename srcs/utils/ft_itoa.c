/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghis <eghis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 19:59:32 by eghis             #+#    #+#             */
/*   Updated: 2021/07/16 16:30:26 by eghis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	get_len(int n, int minus)
{
	int	len;

	len = 1;
	n /= 10;
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len + minus);
}

static int	get_abs(int n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}

char	*ft_itoa(int n)
{
	int		minus;
	int		len;
	char	*str;

	minus = 0;
	if (n < 0)
		minus = 1;
	len = get_len(n, minus);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	str[len--] = '\0';
	str[len--] = get_abs(n % 10) + '0';
	n /= 10;
	while (n)
	{
		str[len--] = get_abs(n % 10) + '0';
		n /= 10;
	}
	if (minus == 1)
		str[len] = '-';
	return (str);
}
