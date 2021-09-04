/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghis <eghis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 16:27:10 by eghis             #+#    #+#             */
/*   Updated: 2021/07/16 16:42:14 by eghis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (dest == 0 || src == 0)
		return (0);
	while (size != 0 && i < size - 1 && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	if (size != 0)
	{
		dest[i] = '\0';
	}
	i = 0;
	while (src[i] != '\0')
		i++;
	return (i);
}
