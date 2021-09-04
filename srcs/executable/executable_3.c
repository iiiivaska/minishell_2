/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executable_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghis <eghis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 13:00:58 by eghis             #+#    #+#             */
/*   Updated: 2021/07/17 18:20:49 by eghis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	close_wait(int status, int *fd)
{
	close(fd[0]);
	close(fd[1]);
	waitpid(g_sig.pid, &status, 0);
	if (status == 32256 || status == 32512)
		status = status / 256;
	else
	{
		if (status != 3)
		{
			if (status > 0)
				status = !!status;
			else
				status = 0;
		}
		else
			status = 131;
	}
	g_sig.exit_stat = status;
}

void	unlink_close(t_all *all, t_pipe *node)
{
	unlink(node->heredoc);
	all->fd_heredoc = 0;
	close(node->fdout);
	close(node->fdin);
	node->fdin = 0;
	node->fdout = 1;
	dup2(all->in, STDIN);
	dup2(all->out, STDOUT);
}
