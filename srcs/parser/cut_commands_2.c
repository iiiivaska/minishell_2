/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_commands_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghis <eghis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 17:07:28 by eghis             #+#    #+#             */
/*   Updated: 2021/07/16 17:24:21 by eghis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	add_list_std(t_all *all, char *str, int pipe)
{
	ft_lstadd_back(&(all->commands), ft_lstnew(ft_strdup(str), 0, pipe));
}

void	clear_str_2(char *str)
{
	str[0] = ' ';
	str[1] = ' ';
}

int	check_sym(char *str)
{
	if (ft_strlen(str) > 1)
	{
		if (str[0] == '<' && str[1] == '<')
		{
			clear_str_2(str);
			return (AN_BR_L_D);
		}
		if (str[0] == '>' && str[1] == '>')
		{
			clear_str_2(str);
			return (AN_BR_R_D);
		}
	}
	if (str[0] == '<')
	{
		str[0] = ' ';
		return (AN_BR_L);
	}
	if (str[0] == '>')
	{
		str[0] = ' ';
		return (AN_BR_R);
	}
	return (0);
}

char	*cpy(char *str, int *i)
{
	char	*str_2;
	int	 	k;

	k = 0;
	str_2 = (char *)malloc(sizeof(char) * (*i + 1));
	while (k < *i)
	{
		str_2[k] = str[k];
		k++;
	}
	str_2[k] = '\0';
	return (str_2);
}

char	*cut_redir_from_str(t_all *all, char *str, int *i)
{
	while (str[*i] && ft_isspace(str[*i]))
		*i = *i + 1;
	while (str[*i] && !is_spec(str[*i]) && str[*i] != ' ')
	{
		if (str[*i] == '\"')
		{
			(*i)++;
			while (str[*i] && str[*i] != '\"')
				(*i)++;
		}
		if (str[*i] == '\'')
		{
			(*i)++;
			while (str[*i] && str[*i] != '\'')
				(*i)++;
		}
		*i = *i + 1;
	}
	while (str[*i] && ft_isspace(str[*i]))
		*i = *i + 1;
	return (cpy(str, i));
}
