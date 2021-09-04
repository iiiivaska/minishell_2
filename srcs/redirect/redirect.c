/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghis <eghis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 14:54:03 by eghis             #+#    #+#             */
/*   Updated: 2021/07/16 17:23:41 by eghis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	create_heredoc_name(t_all *all, t_pipe *pipe, int i, int k)
{
	char	*name;
	char	*name_2;
	char	*str_i;
	char	*str_k;

	str_i = ft_itoa(i);
	str_k = ft_itoa(k);
	name = ft_strjoin(all->heredoc, str_i);
	name_2 = ft_strjoin(name, str_k);
	free(str_i);
	free(str_k);
	free(name);
	if (pipe->heredoc)
		free(pipe->heredoc);
	pipe->heredoc = name_2;
}

void	double_back_redirect(t_all *all, t_list *node, t_pipe *pipe)
{
	char	*str;

	g_sig.dyn = 1;
	all->fd_heredoc = open(pipe->heredoc, O_CREAT | O_WRONLY | O_TRUNC, 0666);
	if (all->fd_heredoc < 0)
	{
		pipe->redir_error = 1;
		return ;
	}
	while (1)
	{
		all->her_str = readline("> ");
		if (!all->her_str)
		{
			doub_back_3(all, 1);
			break ;
		}
		if (!ft_strcmp(all->her_str, node->com))
		{
			doub_back_3(all, 2);
			break ;
		}
		doub_back_2(all, node);
	}
	out_doub_back_redir(all, pipe);
}

int	find_and_start_doub_back_redir(t_all *all, t_pipe *node, int z)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (node->list[i])
	{
		if (node->list[i]->sym == AN_BR_L_D)
		{
			k = i;
			if (node->heredoc)
				unlink(node->heredoc);
			create_heredoc_name(all, node, i, z);
			double_back_redirect(all, node->list[i], node);
		}
		i++;
	}
	return (k);
}

void	find_and_start_sin_back_redir(t_all *all, t_pipe *node, int p_d)
{
	int	i;
	int	fd;
	int	k;

	k = 0;
	i = 0;
	fd = 0;
	while (node->list[i])
	{
		if (node->list[i]->sym == AN_BR_L)
		{
			if (fd)
				close(fd);
			fd = open(node->list[i]->com, O_RDONLY, 0);
			if (fd < 0)
			{
				err_red(all, node, i);
				return ;
			}
			k = i + 1;
		}
		i++;
	}
	back_redir_2(k, p_d, fd, node);
}

void	find_and_start_right_redir(t_all *all, t_pipe *node)
{
	int	i;
	int	fd;

	fd = 0;
	i = 0;
	while (node->list[i])
	{
		if (node->list[i]->sym == AN_BR_R)
		{
			if (fd)
				close(fd);
			fd = open(node->list[i]->com, O_CREAT
					| O_WRONLY | O_TRUNC, 0666);
		}
		if (node->list[i]->sym == AN_BR_R_D)
		{
			if (fd)
				close(fd);
			fd = open(node->list[i]->com, O_CREAT
					| O_WRONLY | O_APPEND, 0666);
		}
		i++;
	}
	if (fd)
		node->fdout = fd;
}
