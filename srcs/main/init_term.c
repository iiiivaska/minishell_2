/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_term.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghis <eghis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 14:27:01 by eghis             #+#    #+#             */
/*   Updated: 2021/07/16 14:27:19 by eghis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	init_term(t_all *all)
{
	char	*termtype;

	if (!isatty(STDIN_FILENO))
		ft_exit(all, "Terminal not found");
	termtype = ft_getenv(all, "TERM");
	if (termtype == NULL || tgetent(0, termtype) != 1)
		ft_exit(all, "Termtype error");
}
