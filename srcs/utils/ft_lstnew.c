/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghis <eghis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 13:30:59 by eghis             #+#    #+#             */
/*   Updated: 2021/07/16 16:39:43 by eghis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_list	*ft_lstnew(char *command, int sym, int pipe)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (new == 0)
		return (0);
	new->pipe = pipe;
	new->command = command;
	new->com = 0;
	new->command_2 = 0;
	new->sym = sym;
	new->args = (char **)malloc(sizeof(char *) * 1);
	new->args[0] = 0;
	new->next = 0;
	new->quot_com = 0;
	return (new);
}

t_env	*ft_lstnew_env(char *value, char *key)
{
	t_env	*new;

	new = (t_env *)malloc(sizeof(t_env));
	if (new == 0)
		return (0);
	new->key = key;
	new->value = value;
	return (new);
}
