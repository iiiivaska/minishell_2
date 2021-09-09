/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghis <eghis@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 11:26:55 by bsadie            #+#    #+#             */
/*   Updated: 2021/09/09 19:33:36 by eghis            ###   ########.fr       */
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
			{
				free(env->value);
				env->value = 0;
			}
			env->value = ft_strdup(value);
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
	//printf("%s | %s\n",str[i], str[i+1]);
	if (!str[i])
		ft_export_no_arg(all->env_l);
	while (str[i])
	{
		value = get_key(all, str[i]);
		key = get_value(all, str[i]);
		printf("%s | %s\n", key, value);
		if (!is_key_in_env(all, key))
		{
			replace_value(all->env_l, key, value);
			replace_value(all->hidden_env, key, value);
		}
		else
		{
			ft_lstadd_back_env(&(all->env_l), ft_lstnew_env(ft_strdup(value), ft_strdup(key)));
			ft_lstadd_back_env(&(all->hidden_env), ft_lstnew_env(ft_strdup(value), ft_strdup(key)));
		}
		free(value);
		free(key);
		i++;
	}
	return (0);
}
