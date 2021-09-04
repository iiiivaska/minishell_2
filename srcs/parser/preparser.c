/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghis <eghis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 18:12:02 by eghis             #+#    #+#             */
/*   Updated: 2021/07/17 14:07:13 by eghis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	check_symbols(t_all *all)
{
	int	i;

	i = 0;
	while (all->command[i])
	{
		skip_quotes(all, &i);
		if (all->command[i] == '\\')
			all->error = SLASH;
		if (all->error != 0)
			return ;
		i++;
	}
}

void	check_pipes_post(t_all *all)
{
	int	i;

	i = 0;
	while (all->command[i])
	{
		skip_quotes(all, &i);
		if (all->command[i] == '|' && all->command[i + 1] == '|')
		{
			all->error = DPIPE;
			return ;
		}
		if (all->command[i] == '|')
		{
			i++;
			while (all->command[i] && (ft_isspace(all->command[i])))
				i++;
			if (all->command[i] == '\0' || all->command[i] == '|')
				all->error = EPIPE;
		}
		if (all->error)
			return ;
		i++;
	}
}

void	check_pipes_pre(t_all *all)
{
	int	i;
	int	k;

	i = 0;
	while (all->command[i])
	{
		skip_quotes(all, &i);
		if (all->command[i] == '|' && i > 0)
		{
			k = i;
			k--;
			while (k >= 0 && (ft_isspace(all->command[k])))
				k--;
			if (k <= 0 || all->command[k] == '|')
				all->error = EPIPE;
		}
		if (all->error)
			return ;
		i++;
	}
}

void	check_redir(t_all *all)
{
	int	i;
	int	k;

	i = 0;
	while (all->command[i])
	{
		skip_quotes(all, &i);
		if (all->command[i + 1] == '\0')
			return ;
		if (all->command[i] == '<' && all->command[i + 1] == '<'
			&& all->command[i + 2] == '<')
			all->error = DREDIR;
		if (all->command[i] == '>' && all->command[i + 1] == '>'
			&& all->command[i + 2] == '>')
			all->error = DREDIR;
		if (all->error)
			return ;
		i++;
	}
}

void	preparser(t_all *all)
{
	check_quotes(all);
}
