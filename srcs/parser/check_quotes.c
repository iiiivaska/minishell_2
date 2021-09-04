/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghis <eghis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 18:14:40 by eghis             #+#    #+#             */
/*   Updated: 2021/07/17 14:06:49 by eghis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	check_quotes(t_all *all)
{
	int	i;

	i = 0;
	while (all->command[i])
	{
		if (all->command[i] == '\"')
		{
			i++;
			while (all->command[i] && all->command[i] != '\"')
				i++;
			if (all->command[i] == '\0')
				all->error = DOUBQUOTNI;
		}
		if (all->command[i] == '\'')
		{
			i++;
			while (all->command[i] && all->command[i] != '\'')
				i++;
			if (all->command[i] == '\0')
				all->error = QUOTNI;
		}
		i++;
	}
}
