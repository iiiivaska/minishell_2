/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghis <eghis@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 22:41:45 by eghis             #+#    #+#             */
/*   Updated: 2021/09/10 22:41:58 by eghis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_clear_t_env(t_env *env)
{
	t_env	*temp;
	t_env	*s_temp;

	if (env)
	{
		temp = env;
		while (temp != 0)
		{
			if (temp->key)
				free(temp->key);
			if (temp->value)
				free(temp->value);
			s_temp = temp;
			temp = temp->next;
			free(s_temp);
		}
	}
}
