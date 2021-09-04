/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghis <eghis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 13:40:14 by eghis             #+#    #+#             */
/*   Updated: 2021/07/16 16:37:09 by eghis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*node;

	node = lst;
	if (lst == 0)
		return (0);
	while (node->next != 0)
		node = node->next;
	return (node);
}

t_pipe	*ft_lstlast_2(t_pipe *lst)
{
	t_pipe	*node;

	node = lst;
	if (lst == 0)
		return (0);
	while (node->next != 0)
		node = node->next;
	return (node);
}

t_env	*ft_lstlast_env(t_env *lst)
{
	t_env	*node;

	node = lst;
	if (lst == 0)
		return (0);
	while (node->next != 0)
		node = node->next;
	return (node);
}
