/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsadie <bsadie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 16:28:15 by bsadie            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2021/09/08 10:03:53 by eghis            ###   ########.fr       */
=======
/*   Updated: 2021/09/08 11:56:42 by bsadie           ###   ########.fr       */
>>>>>>> norm cd.c
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_cd(t_list *node)
{
	char	**args;

	args = node->args;
	if (ft_arrsize(args) > 2)
	{
		printf("minishell: cd: %s\n", strerror(E2BIG));
		return (2);
	}
	if (chdir(args[1]))
	{
		printf("minishell: cd: %s\n", strerror(errno));
		return (1);
	}
	return (0);
}
