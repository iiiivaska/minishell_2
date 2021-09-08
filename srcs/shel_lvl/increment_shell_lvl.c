/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   increment_shell_lvl.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghis <eghis@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 16:16:47 by eghis             #+#    #+#             */
/*   Updated: 2021/09/08 10:29:26 by eghis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	increment(t_env *env)
{
	int		lvl;

	lvl = ft_atoi(env->value) + 1;
	free(env->value);
	env->value = ft_itoa(lvl);
}

void	increment_shell_lvl(t_all *all)
{
	t_env	*env;

	env = all->env_l;
	while (env)
	{
		if (!ft_strcmp(env->key, "SHLVL"))
		{
			increment(env);
			break ;
		}
		env = env->next;
	}
	env = all->hidden_env;
	while (env)
	{
		if (!ft_strcmp(env->key, "SHLVL"))
		{
			increment(env);
			break ;
		}
		env = env->next;
	}
}
