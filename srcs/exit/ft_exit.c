/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghis <eghis@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 13:46:23 by eghis             #+#    #+#             */
/*   Updated: 2021/09/10 17:31:18 by eghis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_exit(t_all *all, char *error)
{
	if (g_sig.ch == 0)
		printf("exit\n");
	if (all)
		clean(all);
	if (error)
		printf("Exit: %s", error);
	exit(g_sig.exit_stat);
}
