/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_pipe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghis <eghis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 16:18:57 by eghis             #+#    #+#             */
/*   Updated: 2021/07/16 16:38:22 by eghis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_pipe	*ft_lstnew_pipe(int size)
{
	t_pipe	*new;

	new = (t_pipe *)malloc(sizeof(t_pipe));
	if (new == 0)
		return (0);
	new->list = (t_list **)malloc(sizeof(t_list) * (size + 1));
	new->next = 0;
	new->fdin = STDIN;
	new->fdout = STDOUT;
	new->heredoc = 0;
	new->redir_error = 0;
	return (new);
}
