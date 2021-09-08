/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghis <eghis@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 14:32:27 by eghis             #+#    #+#             */
/*   Updated: 2021/09/08 10:09:02 by eghis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_sig	g_sig;

void	start_shell(t_all *all)
{
	parser(all);
	if (!all->error)
		executable(all);
	if (all->error != 228 && all->error != 229)
	{
		ft_free_path(all);
		ft_lstclear(&(all->commands), &del);
		ft_lstclear_pipe(&(all->pipe));
		free(all->pipe);
	}
	all->error = 0;
	all->redir_error = 0;
	all->fd_heredoc = -1;
}

void	read_line(t_all *all)
{
	init_signals();
	all->command = readline(PROMPT);
	if (!all->command)
	{
		write(1, "\x1B[1F", 4);
		write(1, PROMPT, ft_strlen(PROMPT));
		ft_exit(all, NOERROR);
	}
	if (ft_strlen(all->command) > 0)
		add_history(all->command);
	// if (!ft_strcmp(all->command, "exit\0"))
	// 	ft_exit(all, NOERROR);
	start_shell(all);
	if (all->command)
		free(all->command);
}

int	main(int ac, char **av, char **env)
{
	t_all	all;

	init_all(&all);
	all.out = dup(STDOUT);
	all.in = dup(STDIN);
	(void)ac;
	(void)av;
	copy_env(&all, env);
	increment_shell_lvl(&all);
	init_term(&all);
	g_sig.exit_stat = 0;
	while (1)
	{
		read_line(&all);
	}
}
