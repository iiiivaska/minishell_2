/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghis <eghis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 16:23:38 by eghis             #+#    #+#             */
/*   Updated: 2021/07/16 16:23:55 by eghis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_free_path(t_all *all)
{
	int	i;

	i = 0;
	if (all->path)
	{
		while (all->path[i])
		{
			free(all->path[i]);
			i++;
		}
		free(all->path);
	}
}
