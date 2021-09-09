/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_commands_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghis <eghis@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 17:09:44 by eghis             #+#    #+#             */
/*   Updated: 2021/09/09 15:15:00 by eghis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	add_commands_to_list(t_all *all, char **redir, int pipe)
{
	int	i;
	int	pipe_c;

	i = 0;
	pipe_c = 0;
	while (redir[i])
	{
		if (redir[i + 1] == 0 && pipe == 1)
			pipe_c = 1;
		if (is_spec(redir[i][0]))
			add_list_spec(all, redir[i], pipe_c);
		else
			add_list_std(all, redir[i], pipe_c);
		i++;
	}
}

void	free_redir(char **redir)
{
	int	i;

	i = 0;
	if (!redir)
		return ;
	while (redir[i])
		free(redir[i++]);
	free(redir);
}

void	cut_redir(t_all *all, char *str, int pipe)
{
	int		z[2];
	char	**redir;

	redir = 0;
	z[1] = 0;
	z[0] = 0;
	while (str[z[0]])
	{
		skip_quotes_str(str, &z[0]);
		if (is_spec(str[z[0]]))
		{
			if (z[0] != z[1])
			{
				redir = cut_redir_2(all, z, str, redir);
				z[1] = z[0];
			}
			if (str[z[0] + 1] == '>' || str[z[0] + 1] == '<')
				z[0]++;
		}
		z[0]++;
	}
	redir = cut_redir_2(all, z, str, redir);
	z[0] = 0;
	add_commands_to_list(all, redir, pipe);
	free_redir(redir);
}

void	pipes_pipe(t_all *all, char **pipes, int pipe, int i)
{
	while (pipes[i])
	{
		if (pipes[i + 1] != 0)
			pipe = 1;
		else
			pipe = 0;
		cut_redir(all, pipes[i], pipe);
		i++;
	}
}

void	cut_commands(t_all *all)
{
	int		i;
	int		t;
	char	**pipes;
	int		pipe;

	pipes = 0;
	pipe = 0;
	i = 0;
	t = 0;
	while (all->command[i])
	{
		skip_quotes(all, &i);
		if (all->command[i] == '|')
		{
			pipes = cut_pipes(all, i, t, pipes);
			t = i + 1;
		}
		i++;
	}
	pipes = cut_pipes(all, i, t, pipes);
	i = 0;
	pipes_pipe(all, pipes, pipe, i);
	free_pipes(pipes);
}
