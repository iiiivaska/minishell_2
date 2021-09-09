/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enviroment_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghis <eghis@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 17:53:34 by eghis             #+#    #+#             */
/*   Updated: 2021/09/09 15:14:03 by eghis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	insert_str(t_all *all, char *str, int *i, t_list *node)
{
	int		str_s;
	char	*new_str;
	int		k;
	int		z;

	z = 0;
	k = 0;
	cut_path(all, *i, node);
	str_s = ft_strlen(str);
	new_str = new_str_c(str_s, ft_strlen(node->command), all);
	while (k < *i)
	{
		new_str[k] = node->command[k];
		k++;
	}
	while (str[z])
		new_str[k++] = str[z++];
	z = *i;
	while (node->command[z])
		new_str[k++] = node->command[z++];
	new_str[k] = '\0';
	*i = *i + str_s - 1;
	free(node->command);
	free(str);
	node->command = new_str;
}

void	replace_env_3(t_all *all, t_list *node)
{
	int	 i;
	int	 d_q;

	d_q = 0;
	i = 0;
	while (node->command[i])
	{
		if (node->command[i] == '\"')
		{
			if (d_q == 0)
				d_q = 1;
			else
				d_q = 0;
		}
		if (node->command[i] == '\'' && d_q == 0)
		{
			i++;
			while (node->command[i] && node->command[i] != '\'')
				i++;
		}
		if (node->command[i] == '$')
			insert_str(all, get_env(all, i, node), &i, node);
		i++;
	}
}

void	replace_env(t_all *all)
{
	t_list	*node;

	node = all->commands;
	while (node)
	{
		if (node->sym != AN_BR_L_D)
		{
			replace_env_3(all, node);
		}
		node = node->next;
	}
}
