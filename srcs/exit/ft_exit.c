/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghis <eghis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 13:46:23 by eghis             #+#    #+#             */
/*   Updated: 2021/07/17 14:18:00 by eghis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_exit(t_all *all, char *error)
{
	printf("exit\n");
	if (all)
		clean(all);
	if (error)
		printf("Exit: %s", error);
	exit(g_sig.exit_stat);
}
