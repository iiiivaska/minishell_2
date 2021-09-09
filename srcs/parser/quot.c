/* ************************************************************************** */
/*	*/
/*	:::	  ::::::::   */
/*   quot.c	 :+:	  :+:	:+:   */
/*	+:+ +:+	 +:+	 */
/*   By: eghis <eghis@student.42.fr>	+#+  +:+	   +#+	*/
/*	+#+#+#+#+#+   +#+	   */
/*   Created: 2021/06/29 21:26:54 by eghis	 #+#	#+#	 */
/*   Updated: 2021/07/16 18:16:24 by eghis	###   ########.fr	   */
/*	*/
/* ************************************************************************** */

#include "../includes/minishell.h"

void	cut_q(t_all *all, t_list *lst, int i)
{
	int		k;
	char	*new_com;

	k = 0;
	new_com = (char *)malloc(sizeof(char) * ft_strlen(lst->com));
	if (new_com == NULL)
		ft_exit(all, strerror(errno));
	while (k < i)
	{
		new_com[k] = lst->com[k];
		k++;
	}
	i++;
	while (lst->com[i])
		new_com[k++] = lst->com[i++];
	new_com[k] = '\0';
	free(lst->com);
	lst->com = new_com;
}

void	cut_quot(t_all *all)
{
	int		i;
	t_list	*node;

	node = all->commands;
	while (node != 0)
	{
		i = 0;
		cut_quot_2(all, node, i);
		node = node->next;
	}
}

void	cut_q_2(t_all *all, t_list *lst, int i, int z)
{
	int		k;
	char	*new_com;

	k = 0;
	new_com = (char *)malloc(sizeof(char) * ft_strlen(lst->args[z]));
	if (new_com == NULL)
		ft_exit(all, strerror(errno));
	while (k < i)
	{
		new_com[k] = lst->args[z][k];
		k++;
	}
	i++;
	while (lst->args[z][i])
		new_com[k++] = lst->args[z][i++];
	new_com[k] = '\0';
	free(lst->args[z]);
	lst->args[z] = new_com;
}

void	cut_quot_args_2(t_list *node, t_all *all, int k, int i)
{
	while (node->args[k][i])
	{
		if (node->args[k][i] == '\'')
		{
			node->quot_com = 1;
			cut_q_2(all, node, i, k);
			while (node->args[k][i] != '\'')
				i++;
			cut_q_2(all, node, i, k);
		}
		if (!node->args[k][i])
			break ;
		if (node->args[k][i] == '\"')
		{
			node->quot_com = 1;
			cut_q_2(all, node, i, k);
			while (node->args[k][i] != '\"')
				i++;
			cut_q_2(all, node, i, k);
		}
		else
			i++;
	}
}

void	cut_quot_args(t_all *all)
{
	int		i;
	t_list	*node;
	int		k;

	node = all->commands;
	while (node != 0)
	{
		k = 0;
		while (node->args[k])
		{
			i = 0;
			cut_quot_args_2(node, all, k, i);
			k++;
		}
		node = node->next;
	}
}
