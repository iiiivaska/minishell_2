/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enviroment_4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsadie <bsadie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 18:05:02 by eghis             #+#    #+#             */
/*   Updated: 2021/09/09 18:00:13 by bsadie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	insert_str_2(t_all *all, char *str, int *i)
{
	int		str_s;
	char	*new_str;
	int		k;
	int		z;

	z = 0;
	k = 0;
	cut_path_2(all, *i);
	str_s = ft_strlen(str);
	new_str = new_str_o(all, str_s, ft_strlen(all->her_str));
	while (k < *i)
	{
		new_str[k] = all->her_str[k];
		k++;
	}
	while (str[z])
		new_str[k++] = str[z++];
	z = *i;
	while (all->her_str[z])
		new_str[k++] = all->her_str[z++];
	new_str[k] = '\0';
	*i = *i + str_s - 1;
	free(all->her_str);
	free(str);
	all->her_str = new_str;
}

void	replace_env_2(t_all *all)
{
	int	i;
	int	d_q;

	d_q = 0;
	i = 0;
	while (all->her_str[i])
	{
		if (all->her_str[i] == '$')
			insert_str_2(all, get_env_2(all, i), &i);
		i++;
	}
}
