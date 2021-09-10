/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghis <eghis@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 22:40:19 by eghis             #+#    #+#             */
/*   Updated: 2021/09/10 22:40:42 by eghis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	get_red_fd(t_all *all, int i, t_pipe *node, int fd)
{
	int	fd_n;

	if (fd)
		close(fd);
	fd_n = open(node->list[i]->com, O_CREAT
			| O_WRONLY | O_TRUNC, 0666);
	if (!fd_n)
		ft_exit(all, strerror(errno));
	return (fd_n);
}

int	get_fd(t_all *all, t_pipe *node, int i)
{
	int	fd;

	fd = open(node->list[i]->com, O_RDONLY, 0);
	if (!fd)
		ft_exit(all, strerror(errno));
	return (fd);
}
