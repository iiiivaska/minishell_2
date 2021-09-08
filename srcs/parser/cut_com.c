/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_com.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghis <eghis@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 19:56:42 by eghis             #+#    #+#             */
/*   Updated: 2021/09/08 09:51:47 by eghis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	del_com(t_all *all, t_list *node, int k)
{
	int		i;
	char	*new_com;

	i = 0;
	new_com = (char *)malloc(sizeof(char) * (ft_strlen(node->command) - k + 1));
	if (new_com == NULL)
		ft_exit(all, strerror(errno));
	if (node->command[k])
		k++;
	while (node->command[k])
		new_com[i++] = node->command[k++];
	new_com[i] = '\0';
	free(node->command);
	node->command = new_com;
}

// void	cut_com_br_s(t_all *all, t_list *node)
// {
// 	int		i;
// 	int		k;
// 	char	*com;

// 	i = 1;
// 	k = 0;
// 	while (node->command_2[i] && node->command_2[i] != '\'')
// 		i++;
// 	com = (char *)malloc(sizeof(char) * (i));
// 	if (errno)
// 		ft_exit(all, strerror(errno));
// 	while (k < i - 1)
// 	{
// 		com[k] = node->command_2[k + 1];
// 		k++;
// 	}
// 	com[k] = '\0';
// 	node->com = com;
// 	del_com(all, node, i);
// }

// void	cut_com_br_d(t_all *all, t_list *node)
// {
// 	int		i;
// 	int		k;
// 	char	*com;

// 	i = 1;
// 	k = 0;
// 	while (node->command_2[i] && node->command_2[i] != '\"')
// 		i++;
// 	com = (char *)malloc(sizeof(char) * (i));
// 	if (errno)
// 		ft_exit(all, strerror(errno));
// 	while (k < i - 1)
// 	{
// 		com[k] = node->command_2[k + 1];
// 		k++;
// 	}
// 	com[k] = '\0';
// 	node->com = com;
// 	del_com(all, node, i);
// }

void	skip(t_list *node, int *i)
{
	while (node->command[*i] && node->command[*i] != ' ')
	{
		if (node->command[*i] == '\"')
		{
			*i = *i + 1;
			while (node->command[*i] && node->command[*i] != '\"')
				*i = *i + 1;
		}
		if (node->command[*i] == '\'')
		{
			*i = *i + 1;
			while (node->command[*i] && node->command[*i] != '\'')
				*i = *i + 1;
		}
		*i = *i + 1;
	}
}

void	cut_com_sp(t_all *all, t_list *node)
{
	int		i;
	int		k;
	char	*com;

	i = 0;
	k = 0;
	skip(node, &i);
	com = (char *)malloc(sizeof(char) * (i + 2));
	if (com == NULL)
		ft_exit(all, strerror(errno));
	while (k < i)
	{
		com[k] = node->command[k];
		k++;
	}
	com[k] = '\0';
	node->com = com;
}

void	cut_com(t_all *all)
{
	t_list	*node;

	node = all->commands;
	while (node)
	{
		cut_com_sp(all, node);
		node = node->next;
	}
}
