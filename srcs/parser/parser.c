/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghis <eghis@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 13:45:54 by eghis             #+#    #+#             */
/*   Updated: 2021/09/08 10:09:39 by eghis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	parser(t_all *all)
{
	preparser(all);
	if (all->error)
	{
		if (all->error == DOUBQUOTNI)
			printf("Double quotes not inclose\n");
		if (all->error == QUOTNI)
			printf("Quotes not inclose\n");
		return ;
	}
	cut_commands(all);
	cut_space(all);
	replace_env(all);
	cut_com(all);
	cut_param(all);
	cut_quot(all);
	cut_quot_args(all);
	parse_path(all);
	parse_pipe(all);
	check_syntax(all);
	update_cmd(all);
}
