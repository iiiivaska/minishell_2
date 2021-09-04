/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghis <eghis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 14:25:43 by eghis             #+#    #+#             */
/*   Updated: 2021/07/16 14:26:08 by eghis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	init_all(t_all *all)
{
	all->redir_error = 0;
	all->her_str = 0;
	all->fd_heredoc = -1;
	all->heredoc = "heredoc";
	all->in = 0;
	all->out = 0;
	all->command = 0;
	all->error = 0;
	all->path = 0;
	all->env = 0;
	all->pid = 0;
	all->commands = 0;
	all->pipe = 0;
	all->env_l = 0;
	all->hidden_env = 0;
}
