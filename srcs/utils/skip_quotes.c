/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_quotes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghis <eghis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 13:11:43 by eghis             #+#    #+#             */
/*   Updated: 2021/07/16 16:45:04 by eghis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	skip_quotes(t_all *all, int *i)
{
	if (all->command[*i] == '\"')
	{
		(*i)++;
		while (all->command[*i] && all->command[*i] != '\"')
			(*i)++;
	}
	if (all->command[*i] == '\'')
	{
		(*i)++;
		while (all->command[*i] && all->command[*i] != '\'')
			(*i)++;
	}
}

void	skip_quotes_lst(t_list *all, int *i)
{
	if (all->command[*i] == '\"')
	{
		(*i)++;
		while (all->command[*i] && all->command[*i] != '\"')
			(*i)++;
	}
	if (all->command[*i] == '\'')
	{
		(*i)++;
		while (all->command[*i] && all->command[*i] != '\'')
			(*i)++;
	}
}
