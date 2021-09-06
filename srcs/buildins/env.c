/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsadie <bsadie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 15:06:05 by bsadie            #+#    #+#             */
/*   Updated: 2021/09/06 13:33:10 by bsadie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_env_print(t_env *env)
{
	t_env	*tmp;

	tmp = env;
	while(tmp)
	{
		//rscolors key wrong
		ft_putstr_fd(tmp->key, 1);
		ft_putchar('=');
		ft_putstr_fd(tmp->value, 1);
		ft_putchar('\n');
//		ft_putstr_fd("aaaaaaaaaaaaaa", 1);
		tmp = tmp->next;
	}
	return (0);
}

int	ft_env(t_all *all, t_list *node)
{
	char	**args;

	args = node->args;
	/*
	if (ft_arrsize(args) > 1)
	{
		printf("minishell: env: %s\n", strerror(E2BIG));
		return (1);
	}
	*/
//	printf("\n\n\nHELLO MY ENV\n\n\n");
	ft_env_print(all->env_l);
	return (0);
}
