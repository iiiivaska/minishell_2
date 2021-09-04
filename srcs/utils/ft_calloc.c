/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghis <eghis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 17:28:53 by eghis             #+#    #+#             */
/*   Updated: 2021/07/16 16:23:17 by eghis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	*ft_calloc(size_t number, size_t size)
{
	void	*memory;

	memory = malloc(number * size);
	if (!memory)
		return (0);
	ft_bzero(memory, number * size);
	return (memory);
}
