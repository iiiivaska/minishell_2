/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executable_4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghis <eghis@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 17:47:31 by bsadie            #+#    #+#             */
/*   Updated: 2021/09/10 17:33:22 by eghis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_pipes_4(char *path, int status)
{
	if (status != -1)
	{
		free(path);
		exit (status);
	}
}

void	ft_pipes_5(t_all *all, t_pipe *node, int i, int status)
{
	int		k;
	char	**j;

	if (status == -1)
	{
		j = env_to_array(all, all->env_l);
		k = execve(full_path(all, (node->list[i])),
				node->list[i]->args, (char *const *)j);
		if (k == -1)
			free(j);
	}
}

void	ft_pipes_3(t_all *all, int fd_old, t_pipe *node, int *fd)
{
	char	*path;
	int		status;
	int		i;

	i = 0;
	init_signals_2();
	error_dup(fd_old, node, fd);
	close(fd[0]);
	while (node->list[i])
	{	
		path = full_path(all, (node->list[i]));
		if (node->list[i]->sym == 0)
		{
			status = build_in(all, node->list[i]);
			ft_pipes_4(path, status);
			ft_pipes_5(all, node, i, status);
			status = error_message(path);
		}
		free(path);
		i++;
		if (status == -1)
			status = 0;
	}
	exit(status);
}
