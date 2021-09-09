/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsadie <bsadie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 18:51:19 by eghis             #+#    #+#             */
/*   Updated: 2021/09/09 17:55:21 by bsadie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	del(void *str)
{
	free(str);
}

void	ft_clean_env(t_all *all)
{
	int	i;

	i = 0;
	if (all->env)
	{
		while (all->env[i])
		{
			free(all->env[i]);
			i++;
		}
	}
}

void	ft_clean_path(t_all *all)
{
	int	i;

	i = 0;
	if (all->path)
	{
		while (all->path[i])
		{
			free(all->path[i]);
			i++;
		}
	}
}

void	ft_clear_t_env(t_env *env)
{
	t_env	*temp;
	t_env	*s_temp;

	if (env)
	{
		temp = env;
		while (temp != 0)
		{
			if (temp->key)
				free(temp->key);
			if (temp->value)
				free(temp->value);
			s_temp = temp;
			temp = temp->next;
			free(s_temp);
		}
	}
}

// void	ft_clear_pipe(t_all *all)
// {
// 	t_pipe	*temp;
// 	t_pipe	*s_temp;

// 	if (all->pipe)
// 	{
// 		temp = all->pipe;
// 		while (temp != 0)
// 		{
// 			ft_lstclear(&(temp->list), &del);
// 			s_temp = temp;
// 			temp = temp->next;
// 			free(s_temp);
// 		}
// 	}
// }

void	clean(t_all *all)
{
	if (all->command)
		free(all->command);
	ft_lstclear(&(all->commands), &del);
	ft_clean_env(all);
	ft_clean_path(all);
	clear_history();
	ft_clear_t_env(all->env_l);
	//ft_clear_t_env(all->hidden_env);
	//ft_clear_pipe(all);
}
