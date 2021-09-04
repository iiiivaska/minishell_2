/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_quot_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghis <eghis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 18:34:37 by eghis             #+#    #+#             */
/*   Updated: 2021/07/16 18:34:52 by eghis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	cut_quot_2(t_all *all, t_list *node, int i)
{
	while (node->com[i])
	{
		if (node->com[i] == '\'')
		{
			node->quot_com = 1;
			cut_q(all, node, i);
			while (node->com[i] != '\'')
				i++;
			cut_q(all, node, i);
		}
		if (!node->com[i])
			break ;
		if (node->com[i] == '\"')
		{
			node->quot_com = 1;
			cut_q(all, node, i);
			while (node->com[i] != '\"')
				i++;
			cut_q(all, node, i);
		}
		else
			i++;
	}
}
