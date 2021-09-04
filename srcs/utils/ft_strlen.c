/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghis <eghis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 12:29:28 by eghis             #+#    #+#             */
/*   Updated: 2021/07/16 16:42:17 by eghis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

size_t	ft_strlen(const char *string)
{
	size_t		sum;
	const char	*ptr;

	ptr = string;
	sum = 0;
	while (*ptr)
	{
		sum++;
		ptr++;
	}
	return (sum);
}
