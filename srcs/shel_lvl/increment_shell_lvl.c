/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   increment_shell_lvl.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghis <eghis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 16:16:47 by eghis             #+#    #+#             */
/*   Updated: 2021/07/16 16:17:42 by eghis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	increment(t_all *all, t_env *env)
{
	char	*new_lvl;
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
			increment(all, env);
			break ;
		}
		env = env->next;
	}
	env = all->hidden_env;
	while (env)
	{
		if (!ft_strcmp(env->key, "SHLVL"))
		{
			increment(all, env);
			break ;
		}
		env = env->next;
	}
}
