/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executable_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghis <eghis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 12:58:36 by eghis             #+#    #+#             */
/*   Updated: 2021/07/17 18:21:50 by eghis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	build_in(t_all *all, t_list *node)
{
	if (!ft_strcmp(node->com, "echo"))
		return (ft_echo(node->args));
	return (-1);
}

int	error_message(char *path)
{
	DIR	*folder;
	int	fd;
	int	ret;

	fd = open(path, O_WRONLY);
	folder = opendir(path);
	ft_putstr_fd("minishell: ", STDERR);
	ft_putstr_fd(path, STDERR);
	if (ft_strchr(path, '/') == NULL)
		ft_putendl_fd(": command not found", STDERR);
	else if (fd == -1 && folder == NULL)
		ft_putendl_fd(": No such file or directory", STDERR);
	else if (fd == -1 && folder != NULL)
		ft_putendl_fd(": is a directory", STDERR);
	else if (fd != -1 && folder == NULL)
		ft_putendl_fd(": Permission denied", STDERR);
	if (ft_strchr(path, '/') == NULL || (fd == -1 && folder == NULL))
		ret = 127;
	else
		ret = 126;
	if (folder)
		closedir(folder);
	close(fd);
	return (ret);
}

int	ft_pipes_2(int *fd)
{
	if (pipe(fd) == -1)
	{
		g_sig.exit_stat = errno;
		printf("minishell: pipe: %s\n", strerror(errno));
		return (1);
	}
	g_sig.pid = fork();
	ft_delay(1000000);
	if (g_sig.pid < 0)
	{
		printf("minishell: fork: %s\n", strerror(errno));
		g_sig.exit_stat = errno;
		return (1);
	}
	return (0);
}

void	error_dup(int fd_old, t_pipe *node, int *fd)
{
	if (dup2(fd_old, STDIN) == -1)
	{
		printf("minishell: dup2: %s\n", strerror(errno));
		exit(errno);
	}
	if (node->next != 0)
	{
		if (dup2(fd[1], STDOUT) == -1)
		{
			printf("minishell: dup2: %s\n", strerror(errno));
			exit(errno);
		}
	}
	if (node->fdout)
		dup2(node->fdout, STDOUT);
	if (node->fdin)
		dup2(node->fdin, STDIN);
}

void	redir(t_all *all)
{
	int		d_p;
	int		k;
	t_pipe	*node;

	k = 0;
	node = all->pipe;
	while (node)
	{
		d_p = find_and_start_doub_back_redir(all, node, k);
		find_and_start_sin_back_redir(all, node, d_p);
		if (all->redir_error)
		{
			all->redir_error = 0;
			return ;
		}
		find_and_start_right_redir(all, node);
		k++;
		node = node->next;
	}
}
