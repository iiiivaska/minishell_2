/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghis <eghis@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 14:11:17 by eghis             #+#    #+#             */
/*   Updated: 2021/09/09 15:11:28 by eghis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	copy_env_2(t_all *all, char **envp)
{
	int	i;
	int	k;

	k = 0;
	i = 0;
	while (envp[i])
		i++;
	all->env = (char **)malloc(sizeof(char *) * (i + 1));
	if (!all->env)
		ft_exit(all, strerror(errno));
	while (k < i)
	{
		all->env[k] = ft_strdup(envp[k]);
		k++;
	}
	all->env[k] = 0;
}

char	*ft_getenv(t_all *all, char *key)
{
	t_env	*env;

	env = all->env_l;
	while (env)
	{
		if (!ft_strcmp(env->key, key))
			return (env->value);
		env = env->next;
	}
	return (0);
}

int	env_size(t_env *env)
{
	t_env	*env_c;
	int		i;

	i = 0;
	env_c = env;
	while (env_c)
	{
		i++;
		env_c = env_c->next;
	}
	i++;
	return (i);
}

char	**env_to_array(t_all *all, t_env *env)
{
	t_env	*env_c;
	char	**array;
	char	*temp;
	int		i;

	i = 0;
	array = 0;
	env_c = env;
	array = (char **)malloc(sizeof(char *) * (env_size(env) + 2));
	if (!array)
		ft_exit(all, strerror(errno));
	while (env_c)
	{
		temp = ft_strjoin(env_c->key, "=");
		array[i] = ft_strjoin(temp, env_c->value);
		free(temp);
		i++;
		env_c = env_c->next;
	}
	array[i] = 0;
	return (array);
}
