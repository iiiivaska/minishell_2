/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_en.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghis <eghis@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 20:18:32 by eghis             #+#    #+#             */
/*   Updated: 2021/09/10 20:18:45 by eghis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	is_valid_en(char *str)
{
	if (ft_isspace(str[0]) || str[0] == '=')
	{
		ft_putstr_fd("minishell: export: ", STDERR);
		ft_putstr_fd("'", STDERR);
		ft_putstr_fd(str, STDERR);
		ft_putstr_fd("'", STDERR);
		ft_putstr_fd(": ", STDERR);
		ft_putstr_fd("not a valid identifier\n", STDERR);
		return (0);
	}
	return (1);
}
