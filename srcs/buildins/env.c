/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsadie <bsadie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 15:06:05 by bsadie            #+#    #+#             */
/*   Updated: 2021/09/07 13:03:30 by bsadie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_env_print(t_env *env)
{
	t_env	*tmp;

	tmp = env;
	while(tmp)
	{
		if (tmp->value && tmp->value[0])
		{
			ft_putstr_fd(tmp->key, 1);
			ft_putchar('=');
			ft_putstr_fd(tmp->value, 1);
			ft_putchar('\n');
		}
		tmp = tmp->next;
	}
	return (0);
}

int	ft_env(t_all *all, t_list *node)
{
	(void)node;
	ft_env_print(all->env_l);
	return (0);
}
