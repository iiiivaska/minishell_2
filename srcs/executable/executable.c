/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executable.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghis <eghis@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 19:49:57 by eghis             #+#    #+#             */
/*   Updated: 2021/09/10 17:42:10 by eghis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	is_buildin(t_pipe *node)
{
	int	i;

	i = 0;
	while (node->list[i])
	{
		if (!ft_strcmp(node->list[i]->com, "echo"))
			return (1);
		if (!ft_strcmp(node->list[i]->com, "exit"))
			return (1);
		if (!ft_strcmp(node->list[i]->com, "pwd"))
			return (1);
		if (!ft_strcmp(node->list[i]->com, "cd"))
			return (1);
		if (!ft_strcmp(node->list[i]->com, "env"))
			return (1);
		if (!ft_strcmp(node->list[i]->com, "export"))
			return (1);
		if (!ft_strcmp(node->list[i]->com, "unset"))
			return (1);
		i++;
	}
	return (0);
}

void	ft_pipes(t_all *all, t_pipe *node, int fd_old)
{
	int		fd[2];

	if (!node)
		return ;
	if (!node->redir_error)
	{
		if (ft_pipes_2(fd))
			return ;
		if (g_sig.pid == 0)
		{
			g_sig.ch = 1;
			ft_pipes_3(all, fd_old, node, fd);
		}
		else
		{
			close(fd[1]);
			fd_old = fd[0];
		}
		unlink_close(all, node);
	}
	ft_pipes(all, node->next, fd_old);
	if (!node->redir_error)
		close_wait(-1, fd);
	else
		g_sig.exit_stat = 1;
}

void	ft_pipes_7(t_all *all, int fd_old, t_pipe *node, int *fd)
{
	int		status;
	int		i;

	i = 0;
	init_signals();
	error_dup(fd_old, node, fd);
	close(fd[0]);
	while (node->list[i])
	{
		status = build_in(all, node->list[i]);
		if (status != -1)
			break ;
		i++;
	}
	g_sig.exit_stat = status;
}

void	executable(t_all *all)
{
	t_pipe	*node;
	int		fd_old;
	int		fd[2];

	fd_old = STDIN;
	redir(all);
	node = all->pipe;
	if (is_buildin(node) == 1 && node->next == 0)
	{
		if (pipe(fd) == -1)
		{
			g_sig.exit_stat = errno;
			printf("minishell: pipe: %s\n", strerror(errno));
			exit(1);
		}
		ft_pipes_7(all, fd_old, node, fd);
	}
	else
	{
		ft_pipes(all, node, fd_old);
	}
	dup2(0, STDOUT);
	dup2(1, STDIN);
}
