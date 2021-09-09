/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsadie <bsadie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 13:10:38 by eghis             #+#    #+#             */
/*   Updated: 2021/09/09 17:50:37 by bsadie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*join_path(char *path, const char *s)
{
	char	*tmp;
	char	*pth;

	tmp = ft_strjoin(path, "/");
	pth = ft_strjoin(tmp, s);
	free(tmp);
	return (pth);
}

char	*check_dir(char *path, char *command)
{
	DIR				*folder;
	struct dirent	*item;
	char			*pth;

	pth = 0;
	folder = opendir(path);
	if (!folder)
		return (0);
	item = readdir(folder);
	while (item)
	{
		if (ft_strcmp(item->d_name, command) == 0)
			pth = join_path(path, item->d_name);
		item = readdir(folder);
	}
	closedir(folder);
	return (pth);
}

char	*full_path(t_all *all, t_list *node)
{
	int		i;
	char	*full_path;

	full_path = 0;
	i = 0;
	if (node->command[0] != '.' && node->command[0] != '/')
	{
		while (all->path[i])
		{
			full_path = check_dir(all->path[i], node->com);
			if (full_path)
				break ;
			i++;
		}
		if (full_path)
			return (full_path);
	}
	return (node->com);
}
