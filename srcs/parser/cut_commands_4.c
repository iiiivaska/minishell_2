/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_commands_4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghis <eghis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 17:24:48 by eghis             #+#    #+#             */
/*   Updated: 2021/07/16 17:26:04 by eghis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*cut_command_from_str(t_all *all, char *str, int *i)
{
	char	*str_2;
	int	 	k;

	k = 0;
	str_2 = (char *)malloc(sizeof(char) * (ft_strlen(str) - *i + 1));
	while (str[*i])
	{
		str_2[k] = str[*i];
		k++;
		*i = *i + 1;
	}
	str_2[k] = '\0';
	return (str_2);
}

void	add_list_spec(t_all *all, char *str, int pipe)
{
	int	 	i;
	int	 	sym;
	char	*redir;
	char	*com;

	sym = check_sym(str);
	i = 0;
	redir = cut_redir_from_str(all, str, &i);
	com = cut_command_from_str(all, str, &i);
	if (com[0])
		ft_lstadd_back(&(all->commands), ft_lstnew(redir, sym, 0));
	else
		ft_lstadd_back(&(all->commands), ft_lstnew(redir, sym, pipe));
	if (com[0])
		ft_lstadd_back(&(all->commands), ft_lstnew(com, 0, pipe));
	else
		free (com);
}
