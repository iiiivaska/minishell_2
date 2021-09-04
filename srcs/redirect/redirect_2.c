/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghis <eghis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 15:33:07 by eghis             #+#    #+#             */
/*   Updated: 2021/07/16 16:16:07 by eghis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	err_red(t_all *all, t_pipe *node, int i)
{
	ft_putstr_fd("minishell: ", STDERR);
	ft_putstr_fd(node->list[i]->args[0], STDERR);
	ft_putstr_fd(": ", STDERR);
	ft_putstr_fd(strerror(errno), STDERR);
	ft_putstr_fd("\n", STDERR);
	node->redir_error = 1;
	g_sig.exit_stat = 1;
}

void	out_doub_back_redir(t_all *all, t_pipe *pipe)
{
	close(all->fd_heredoc);
	pipe->fdin = open(pipe->heredoc, O_RDONLY, 0666);
	g_sig.dyn = 0;
	g_sig.s_int = 0;
	return ;
}

void	back_redir_2(int k, int p_d, int fd, t_pipe *node)
{
	if (k > p_d)
		node->fdin = fd;
	else
		if (fd)
			close(fd);
}

void	doub_back_2(t_all *all, t_list *node)
{
	if (node->quot_com == 0)
		replace_env_2(all);
	ft_putendl_fd(all->her_str, all->fd_heredoc);
	free(all->her_str);
}

void	doub_back_3(t_all *all, int flag)
{
	if (flag == 1)
	{
		g_sig.dyn = 0;
		write(1, "\x1B[1F> ", 6);
	}
	else
	{
		g_sig.dyn = 0;
		free(all->her_str);
	}
}
