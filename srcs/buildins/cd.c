/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsadie <bsadie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 16:28:15 by bsadie            #+#    #+#             */
/*   Updated: 2021/09/08 13:29:57 by bsadie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_cd(t_list *node)
{
	char	**args;

	args = node->args;
	if (args[1])
	{
		if (ft_arrsize(args) > 2)
		{
			write(STDERR, "minishell: cd: ", 15);
			ft_putendl_fd(strerror(E2BIG), STDERR);
			return (2);
		}
		if (chdir(args[1]))
		{
			write(STDERR, "minishell: cd: ", 15);
			ft_putendl_fd(strerror(errno), STDERR);
			return (1);
		}
	}
	return (0);
}
