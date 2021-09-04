/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghis <eghis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 13:30:03 by eghis             #+#    #+#             */
/*   Updated: 2021/07/16 16:35:14 by eghis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*node;

	if (lst == 0)
		return ;
	if (*lst == 0)
	{
		*lst = new;
		return ;
	}
	node = ft_lstlast(*lst);
	if (node == 0)
		return ;
	node->next = new;
}

void	ft_lstadd_back_2(t_pipe **lst, t_pipe *new)
{
	t_pipe	*node;

	if (lst == 0)
		return ;
	if (*lst == 0)
	{
		*lst = new;
		return ;
	}
	node = ft_lstlast_2(*lst);
	if (node == 0)
		return ;
	node->next = new;
}

void	ft_lstadd_back_env(t_env **lst, t_env *new)
{
	t_env	*node;

	if (lst == 0)
		return ;
	if (*lst == 0)
	{
		*lst = new;
		return ;
	}
	node = ft_lstlast_env(*lst);
	if (node == 0)
		return ;
	node->next = new;
}
