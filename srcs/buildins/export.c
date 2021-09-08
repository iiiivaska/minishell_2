/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsadie <bsadie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 11:26:55 by bsadie            #+#    #+#             */
/*   Updated: 2021/09/08 12:18:11 by bsadie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	replace_value(t_env *oldenv, char *key, char *value)
{
	t_env	*env;

	env = oldenv;
	while (env)
	{
		if (!ft_strcmp(env->key, key))
		{
			if (env->value)
				free(env->value);
			oldenv->value = ft_strdup(value);
			return (0);
		}
		env = env->next;
	}
	return (1);
}

int	is_key_in_env(t_all *all, char *key)
{
	t_env	*env;

	env = all->env_l;
	while (env)
	{
		if (!ft_strcmp(env->key, key))
			return (0);
		env = env->next;
	}
	return (1);
}

int	ft_export(t_all *all, t_list *node)
{
	char	**str;
	int		i;
	char	*key;
	char	*value;

	i = 1;
	str = node->args;
	while (str[i])
	{
		value = get_key(all, str[i]);
		key = get_value(all, str[i]);
		if (!is_key_in_env(all, key))
		{
			replace_value(all->env_l, key, value);
			replace_value(all->hidden_env, key, value);
		}
		else
		{
			ft_lstadd_back_env(&all->env_l, ft_lstnew_env(value, key));
			ft_lstadd_back_env(&all->hidden_env, ft_lstnew_env(value, key));
		}
		i++;
	}
	return (0);
}
