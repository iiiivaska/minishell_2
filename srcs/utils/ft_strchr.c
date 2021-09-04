/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghis <eghis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 13:23:47 by eghis             #+#    #+#             */
/*   Updated: 2021/07/16 16:40:57 by eghis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*ft_strchr(const char *string, int symbol)
{
	while (*string != '\0')
	{
		if (*string == symbol)
			return ((char *)string);
		string++;
	}
	if (*string == symbol)
		return ((char *)string);
	return (0);
}
