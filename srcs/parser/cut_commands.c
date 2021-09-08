/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_commands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghis <eghis@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 16:54:46 by eghis             #+#    #+#             */
/*   Updated: 2021/09/08 10:21:43 by eghis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*cut_str_pipe(t_all *all, int i, int t)
{
	char	*str;
	int		k;

	k = 0;
	str = (char *)malloc(sizeof(char) * (i - t + 1));
	while (t < i)
		str[k++] = all->command[t++];
	str[k] = 0;
	return (str);
}

char	**cut_pipes(t_all *all, int k, int t, char **pipes)
{
	char	**new_pipes;
	int	 	i;

	i = 0;
	if (!pipes)
	{
		new_pipes = (char **)malloc(sizeof(char *) * 2);
		new_pipes[0] = cut_str_pipe(all, k, t);
		new_pipes[1] = 0;
		return (new_pipes);
	}
	while (pipes[i])
		i++;
	new_pipes = (char **)malloc(sizeof(char *) * (i + 2));
	i = 0;
	while (pipes[i])
	{
		new_pipes[i] = pipes[i];
		i++;
	}
	new_pipes[i] = cut_str_pipe(all, k, t);
	i++;
	new_pipes[i] = 0;
	free(pipes);
	return (new_pipes);
}

void	skip_quotes_str(char *str, int *i)
{
	if (str[*i] == '\"')
	{
		(*i)++;
		while (str[*i] && str[*i] != '\"')
			(*i)++;
	}
	if (str[*i] == '\'')
	{
		(*i)++;
		while (str[*i] && str[*i] != '\'')
			(*i)++;
	}
}

char	*cut_str_redir(t_all *all, char *str, int i, int t)
{
	char	*str_n;
	int	 	k;

	all->in = all->in;
	k = 0;
	str_n = (char *)malloc(sizeof(char) * (i - t + 2));
	while (t < i)
		str_n[k++] = str[t++];
	str_n[k] = '\0';
	return (str_n);
}

char	**cut_redir_2(t_all *all, int *z, char *str, char **redir)
{
	char	**new_redir;
	int	 	k;

	k = 0;
	if (!redir)
	{
		new_redir = (char **)malloc(sizeof(char *) * 2);
		new_redir[0] = cut_str_redir(all, str, z[0], z[1]);
		new_redir[1] = 0;
		return (new_redir);
	}
	while (redir[k])
		k++;
	new_redir = (char **)malloc(sizeof(char *) * (k + 2));
	k = 0;
	while (redir[k])
	{
		new_redir[k] = redir[k];
		k++;
	}
	new_redir[k] = cut_str_redir(all, str, z[0], z[1]);
	k++;
	new_redir[k] = 0;
	free(redir);
	return (new_redir);
}
