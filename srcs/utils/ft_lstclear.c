/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghis <eghis@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 18:53:59 by eghis             #+#    #+#             */
/*   Updated: 2021/09/10 19:38:21 by eghis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	free_args(t_list *temp)
{
	int	i;

	i = 0;
	if (temp->args)
	{
		while (temp->args[i])
			free(temp->args[i++]);
		free(temp->args);
	}
}

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;
	t_list	*temp2;

	if (*lst == 0 || lst == 0)
		return ;
	temp = *lst;
	while (temp != 0)
	{
		if (temp->command)
			del(temp->command);
		if (temp->command_2)
			free(temp->command_2);
		free_args(temp);
		if (temp->com)
			free(temp->com);
		temp2 = temp->next;
		free(temp);
		temp = temp2;
	}
	*lst = 0;
}

void	ft_lstclear_pipe(t_pipe **lst)
{
	t_pipe	*temp;
	t_pipe	*temp2;

	if (*lst == 0 || lst == 0)
		return ;
	temp = *lst;
	while (temp != 0)
	{
		if (temp->heredoc)
			free(temp->heredoc);
		free(temp->list);
		temp2 = temp->next;
		free(temp);
		temp = temp2;
	}
	*lst = 0;
}
