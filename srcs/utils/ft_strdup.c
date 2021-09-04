/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghis <eghis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 18:37:42 by eghis             #+#    #+#             */
/*   Updated: 2021/07/16 16:41:35 by eghis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*ft_strdup(const char *str)
{
	char	*str2;
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	str2 = ft_calloc(ft_strlen(str) + 1, sizeof(char));
	if (!str2)
		return (0);
	while (str[i])
	{
		str2[i] = str[i];
		i++;
	}
	str2[i] = '\0';
	return ((void *)str2);
}
