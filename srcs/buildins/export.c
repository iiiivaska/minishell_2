/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsadie <bsadie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 11:26:55 by bsadie            #+#    #+#             */
/*   Updated: 2021/09/09 15:48:18 by bsadie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	replace_value(t_env *oldenv, char *key, char *value)
{
	while (oldenv)
	{
		if (!ft_strcmp(oldenv->key, key))
		{
			if (oldenv->value)
				free(oldenv->value);
			oldenv->value = value;
			return (0);
		}
		oldenv = oldenv->next;
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

int	ft_export_no_arg(t_env *env)
{
	t_env	*tmp;

	tmp = env;
	while (tmp)
	{
		if (tmp->value && tmp->value[0])
		{
			ft_putstr_fd("declare -x ", 1);
			ft_putstr_fd(tmp->key, 1);
			ft_putchar('=');
			ft_putstr_fd(tmp->value, 1);
			ft_putchar('\n');
		}
		tmp = tmp->next;
	}
	return (0);
}

int	ft_export(t_all *all, t_list *node)
{
	char	**str;
	int		i;
	char	*key;
	char	*value;

	i = 1;
	str = node->args;
	if (!str[i])
		ft_export_no_arg(all->env_l);
	while (str[i])
	{
		value = get_key(all, str[i]);
		key = get_value(all, str[i++]);
		if (!is_key_in_env(all, key))
		{
			replace_value(all->env_l, key, value);
			free(key);
		}
		else
		{
			ft_lstadd_back_env(&all->env_l, ft_lstnew_env(value, key));
		}
	}
	return (0);
}
