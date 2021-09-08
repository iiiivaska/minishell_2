/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enviroment.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghis <eghis@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 17:36:15 by eghis             #+#    #+#             */
/*   Updated: 2021/09/08 09:48:33 by eghis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*get_env_name(t_all *all, int i, t_list *node)
{
	char	*name_env;
	int	 	k;

	k = i;
	if (ft_isnum(node->command[i + 1]))
		return (ft_strdup(" "));
	if (node->command[i + 1] == '?')
		return (ft_strdup("?"));
	while (node->command[i] && is_valid_env_name(node->command[i]))
		i = i + 1;
	name_env = (char *)malloc(sizeof(char) * (i - k + 1));
	if (name_env == NULL)
		ft_exit(all, strerror(errno));
	i = k + 1;
	k = 0;
	while (node->command[i] && is_valid_env_name(node->command[i]))
	{
		name_env[k] = node->command[i];
		k++;
		i = i + 1;
	}
	name_env[k] = '\0';
	return (name_env);
}

int	get_env_name_lenght(t_all *all, int i, t_list *node)
{
	char	*name_env;
	int	 	size;

	name_env = get_env_name(all, i, node);
	size = ft_strlen(name_env);
	free(name_env);
	return (size);
}

char	*get_env(t_all *all, int i, t_list *node)
{
	char	*env;
	char	*name_env;

	name_env = get_env_name(all, i, node);
	env = ft_strdup(ft_getenv(all, name_env));
	if (name_env[0] == '?')
	{
		free(env);
		env = ft_itoa(g_sig.exit_stat);
	}
	if (env == 0)
		env = ft_strdup("");
	free(name_env);
	return (env);
}

void	cut_path(t_all *all, int i, t_list *node)
{
	int	 	env_s;
	char	*new_command;
	char	*env_name;
	int	 	k;

	k = 0;
	env_name = get_env_name(all, i, node);
	env_s = ft_strlen(env_name) + 1;
	free(env_name);
	new_command = (char *)malloc(sizeof(char) * (ft_strlen(node->command)
				- env_s) + 1);
	if (new_command == NULL)
		ft_exit(all, strerror(errno));
	while (k < i)
	{
		new_command[k] = node->command[k];
		k++;
	}
	while (node->command[i + env_s])
		new_command[k++] = node->command[i++ + env_s];
	new_command[k] = '\0';
	free(node->command);
	node->command = new_command;
}

char	*new_str_c(int str_s, int com_s, t_all *all)
{
	char	*new_str;

	new_str = (char *)malloc(sizeof(char) * (str_s + com_s + 1));
	if (new_str == NULL)
		ft_exit(all, strerror(errno));
	return (new_str);
}
