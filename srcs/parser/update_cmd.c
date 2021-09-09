/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsadie <bsadie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 14:15:20 by eghis             #+#    #+#             */
/*   Updated: 2021/09/09 18:30:20 by bsadie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	free_args_2(t_pipe *pipe, int ex)
{
	int	i;

	i = 0;
	while (pipe->list[ex]->args[i])
		free(pipe->list[ex]->args[i++]);
	free(pipe->list[ex]->args);
}

void	add_param_pipe(t_all *all, t_pipe *pipe, int ex, int param)
{
	char	**new_args;
	int		i;
	int		k;

	k = 1;
	i = 0;
	while (pipe->list[param]->args[k])
		k++;
	while (pipe->list[ex]->args[i])
		i++;
	new_args = (char **)malloc(sizeof(char *) * (i + 2 + k));
	if (new_args)
		ft_exit(all, strerror(errno));
	i = 0;
	while ((pipe->list[ex]->args[i]) != 0)
	{
		new_args[i] = ft_strdup(pipe->list[ex]->args[i++]);
		//i++;
	}
	new_args[i++] = ft_strdup(pipe->list[param]->com);
	k = 1;
	while (pipe->list[param]->args[k])
		new_args[i++] = ft_strdup(pipe->list[param]->args[k++]);
	new_args[i] = 0;
	free_args_2(pipe, ex);
	pipe->list[ex]->args = new_args;
}

int	find_exec(t_pipe *pipe)
{
	int	i;
	int	k;

	k = -1;
	i = 0;
	while (pipe->list[i])
	{
		if (pipe->list[i]->sym == 0)
		{
			k = i;
			return (k);
		}
		i++;
	}
	return (k);
}

void	update_cmd_2(t_all *all, t_pipe *node, int i)
{
	int	l;

	l = i + 1;
	while (node->list[l])
	{
		if (node->list[l]->sym == 0)
		{
			add_param_pipe(all, node, i, l);
			node->list[l]->sym = -1;
		}
		l++;
	}
}

void	update_cmd(t_all *all)
{
	t_pipe	*node;
	int		ex;

	node = all->pipe;
	while (node)
	{
		ex = find_exec(node);
		if (ex != -1)
			update_cmd_2(all, node, ex);
		node = node->next;
	}
}
