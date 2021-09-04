/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_space.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghis <eghis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 17:28:27 by eghis             #+#    #+#             */
/*   Updated: 2021/07/16 17:35:13 by eghis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	cut_pre_space(t_all *all, t_list *lst)
{
	int		i;
	int		k;
	char	*new_comm;

	i = 0;
	k = 0;
	while (ft_isspace(lst->command[i]))
		i++;
	new_comm = (char *)malloc(sizeof(char) * (ft_strlen(lst->command) - i + 1));
	if (new_comm == NULL)
		ft_exit(all, strerror(errno));
	while (lst->command[i])
		new_comm[k++] = lst->command[i++];
	new_comm[k] = '\0';
	free(lst->command);
	lst->command = new_comm;
}

void	cut_post_space(t_all *all, t_list *lst)
{
	int	 	i;
	int	 	k;
	char	*new_comm;

	i = 0;
	k = 0;
	i = ft_strlen(lst->command) - 1;
	while (ft_isspace(lst->command[i]))
		i--;
	new_comm = (char *)malloc(sizeof(char) * (i + 2));
	if (new_comm == NULL)
		ft_exit(all, strerror(errno));
	while (k <= i)
	{
		new_comm[k] = lst->command[k];
		k++;
	}
	new_comm[k] = '\0';
	free(lst->command);
	lst->command = new_comm;
}

char	*cut_inner(t_list *node, int sp_size, int i)
{
	int		k;
	char	*new_command;

	k = 0;
	new_command = (char *)malloc(sizeof(char)
			* (ft_strlen(node->command) - (sp_size - i) + 2));
	while (k <= i)
	{
		new_command[k] = node->command[k];
		k++;
	}
	while (node->command[sp_size])
		new_command[k++] = node->command[sp_size++];
	new_command[k] = '\0';
	return (new_command);
}

void	cut_inner_space(t_all *all, t_list *node)
{
	int		i;
	int		sp_size;
	char	*new_command;

	i = 0;
	while (node->command[i])
	{
		sp_size = 0;
		skip_quotes_lst(node, &i);
		if (node->command[i] && ft_isspace(node->command[i]))
		{
			sp_size = i;
			while (node->command[sp_size] && ft_isspace(node->command[sp_size]))
				sp_size++;
			new_command = cut_inner(node, sp_size, i);
			free(node->command);
			node->command = new_command;
		}
		i++;
	}
}

void	cut_space(t_all *all)
{
	t_list	*node;

	node = all->commands;
	while (node)
	{
		cut_pre_space(all, node);
		cut_post_space(all, node);
		cut_inner_space(all, node);
		node = node->next;
	}
}
