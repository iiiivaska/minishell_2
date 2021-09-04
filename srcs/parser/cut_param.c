/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_param.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghis <eghis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 14:45:22 by eghis             #+#    #+#             */
/*   Updated: 2021/07/16 17:27:59 by eghis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	add_param(t_list *node, char *param)
{
	int		i;
	char	**new_args;

	i = 0;
	if ((node->args) == 0)
	{
		new_args = (char **)malloc(sizeof(char *) * 3);
		new_args[0] = param;
		new_args[1] = 0;
		node->args = new_args;
		return ;
	}
	while (node->args[i])
		i++;
	new_args = (char **)malloc(sizeof(char *) * (i + 2));
	i = 0;
	while (node->args[i])
	{
		new_args[i] = node->args[i];
		i++;
	}
	new_args[i++] = param;
	new_args[i] = 0;
	free(node->args);
	node->args = new_args;
}

char	*cut_arg(t_all *all, t_list *node, int i, int t)
{
	char	*arg;
	int		z;

	z = 0;
	arg = (char *)malloc(sizeof(char) * (i - t + 1));
	while (t < i)
		arg[z++] = node->command[t++];
	arg[z] = '\0';
	return (arg);
}

void	cut_param_2(t_all *all, t_list *node)
{
	int		i;
	int		t;
	char	*arg;

	arg = 0;
	i = 0;
	t = 0;
	while (node->command[i])
	{
		skip_quotes_lst(node, &i);
		if (node->command[i] == ' ')
		{
			arg = cut_arg(all, node, i, t);
			add_param(node, arg);
			t = i + 1;
		}
		i++;
		if (!node->command[i])
		{
			arg = cut_arg(all, node, i, t);
			add_param(node, arg);
		}
	}
}

void	cut_param(t_all *all)
{
	t_list	*node;

	node = all->commands;
	while (node)
	{
		cut_param_2(all, node);
		node = node->next;
	}
}
