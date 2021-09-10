/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghis <eghis@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 11:19:03 by eghis             #+#    #+#             */
/*   Updated: 2021/09/10 18:26:44 by eghis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*get_value(t_all *all, char	*str)
{
	int		i;
	char	*key;

	i = 0;
	key = 0;
	while (str[i] && str[i] != '=')
		i++;
	key = (char *)malloc(sizeof(char) * (i + 1));
	if (!key)
		ft_exit(all, strerror(errno));
	i = 0;
	while (str[i] && str[i] != '=')
	{
		key[i] = str[i];
		i++;
	}
	key[i] = '\0';
	return (key);
}

char	*get_key(t_all *all, char	*str)
{
	int		i;
	char	*key;
	int		k;

	k = 0;
	i = 0;
	key = 0;
	while (str[i] && str[i] != '=')
		i++;
	if (str[i] == '=' && str[i + 1] != '\0')
	{
		i++;
		key = (char *)malloc(sizeof(char) * (ft_strlen(str) - i + 1));
		if (!key)
			ft_exit(all, strerror(errno));
		while (str[i])
			key[k++] = str[i++];
		key[k] = '\0';
		return (key);
	}
	else
		return (0);
}

void	env_to_list(t_all *all)
{
	int		i;
	char	*key;
	char	*value;

	i = 0;
	while (all->env[i])
	{
		key = get_key(all, all->env[i]);
		if (key != 0)
		{
			value = get_value(all, all->env[i]);
			ft_lstadd_back_env(&(all->env_l), ft_lstnew_env(key, value));
		}
		i++;
	}
}

// void	env_to_list_hidden(t_all *all)
// {
// 	int		i;
// 	char	*key;
// 	char	*value;

// 	i = 0;
// 	while (all->env[i])
// 	{
// 		key = get_key(all, all->env[i]);
// 		if (key != 0)
// 		{
// 			value = get_value(all, all->env[i]);
// 			ft_lstadd_back_env(&(all->hidden_env), ft_lstnew_env(key, value));
// 		}
// 		i++;
// 	}
// }

void	copy_env(t_all *all, char **envp)
{
	copy_env_2(all, envp);
	env_to_list(all);
	//env_to_list_hidden(all);
}
