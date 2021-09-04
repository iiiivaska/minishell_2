/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_commands_5.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghis <eghis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 13:42:32 by eghis             #+#    #+#             */
/*   Updated: 2021/07/17 13:42:44 by eghis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	free_pipes(char **pipes)
{
	int	i;

	i = 0;
	if (pipes == 0)
		return ;
	while (pipes[i])
		free(pipes[i++]);
	free(pipes);
}
