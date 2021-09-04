/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghis <eghis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 12:18:40 by eghis             #+#    #+#             */
/*   Updated: 2021/07/17 13:12:19 by eghis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	pipes_count(t_list *list)
{
	int		i;
	t_list	*node;

	i = 0;
	node = list;
	while (node && node->pipe != PIPE)
	{
		i++;
		node = node->next;
	}
	if (node != 0)
		i++;
	return (i + 1);
}

void	add_commands_pipe(t_all *all, t_list *node, t_pipe *pipe)
{
	t_list	*nd;
	int		i;

	i = 0;
	nd = node;
	while (nd && nd->pipe != PIPE)
	{
		(pipe->list)[i] = nd;
		i++;
		nd = nd->next;
	}
	if (node != 0)
	{
		(pipe->list)[i] = nd;
		i++;
	}
	pipe->list[i] = 0;
}

void	parse_pipe(t_all *all)
{
	t_list	*node;
	t_pipe	*pipe;
	t_pipe	*cur_pipe;

	node = all->commands;
	pipe = 0;
	while (node)
	{
		cur_pipe = ft_lstnew_pipe(pipes_count(node));
		if (pipe == 0)
			pipe = cur_pipe;
		else
			ft_lstadd_back_2(&pipe, cur_pipe);
		add_commands_pipe(all, node, cur_pipe);
		while (node && node->pipe != PIPE)
			node = node->next;
		if (node != 0)
			node = node->next;
	}
	all->pipe = pipe;
}
