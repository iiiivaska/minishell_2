/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsadie <bsadie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 11:34:05 by bsadie            #+#    #+#             */
/*   Updated: 2021/09/07 15:48:49 by bsadie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	free_env_node(t_env *env)
{
	if (env)
	{
		if (env->key)
			free(env->key);
		if (env->value)
			free(env->value);
	//	if (env->next)
	//		free(env->next);
		free(env);
	}
}

t_env	*get_prev(t_env *oldenv, char *key)
{
	t_env	*prev;
	t_env	*env;

	env = oldenv;
	prev = env;
	while (env->next)
	{
		if (!ft_strcmp(env->next->key, key))
			return (prev);
		prev = prev->next;
		env = env->next;
	}
	return (NULL);
}

int	lst_del_node(t_env *oldenv, char *key)
{
	t_env	*env;
	t_env	*next;
	t_env	*prev;

	env = oldenv;
	prev = get_prev(oldenv, key);
	next = oldenv->next;
	while (env)
	{
		if (!ft_strcmp(env->key, key))
		{
			prev->next = env->next;
		//	free_env_node(env);
			return (0);
		}
		env = env->next;
		next = env->next;
	}
	return (0);
}

int	ft_unset(t_all *all, t_list *node)
{
	t_env	*env;
	int		i;
	char	*key;

	i = 1;
	env = all->env_l;
	while(node->args[i])
	{
		key = get_value(all, node->args[i]);
		if (!is_key_in_env(all, key))
		{
			lst_del_node(all->env_l, key);
			lst_del_node(all->hidden_env, key);
		}
		i++;
		free(key);
	}
	return (0);
}