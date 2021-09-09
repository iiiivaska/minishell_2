/* ************************************************************************** */
/*	*/
/*	:::	  ::::::::   */
/*   enviroment_2.c	 :+:	  :+:	:+:   */
/*	+:+ +:+	 +:+	 */
/*   By: eghis <eghis@student.42.fr>	+#+  +:+	   +#+	*/
/*	+#+#+#+#+#+   +#+	   */
/*   Created: 2021/07/16 17:57:30 by eghis	 #+#	#+#	 */
/*   Updated: 2021/07/16 17:58:29 by eghis	###   ########.fr	   */
/*	*/
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*get_env_name_2(t_all *all, int i)
{
	char	*name_env;
	int		k;

	k = i;
	if (ft_isnum(all->her_str[i + 1]))
		return (ft_strdup(" "));
	if (all->her_str[i + 1] == '?')
		return (ft_strdup("?"));
	while (all->her_str[i] && is_valid_env_name(all->her_str[i]))
		i = i + 1;
	name_env = (char *)malloc(sizeof(char) * (i - k + 1));
	if (name_env == NULL)
		ft_exit(all, strerror(errno));
	i = k + 1;
	k = 0;
	while (all->her_str[i] && is_valid_env_name(all->her_str[i]))
	{
		name_env[k] = all->her_str[i];
		k++;
		i = i + 1;
	}
	name_env[k] = '\0';
	return (name_env);
}

int	get_env_name_lenght_2(t_all *all, int i)
{
	char	*name_env;
	int		size;

	name_env = get_env_name_2(all, i);
	size = ft_strlen(name_env);
	free(name_env);
	return (size);
}

char	*get_env_2(t_all *all, int i)
{
	char	*env;
	char	*name_env;

	name_env = get_env_name_2(all, i);
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

void	cut_path_2(t_all *all, int i)
{
	int		env_s;
	char	*new_command;
	char	*env_name;
	int		k;

	k = 0;
	env_name = get_env_name_2(all, i);
	env_s = ft_strlen(env_name) + 1;
	free(env_name);
	new_command = (char *)malloc(sizeof(char) * (ft_strlen(all->her_str)
				- env_s) + 1);
	if (new_command == NULL)
		ft_exit(all, strerror(errno));
	while (k < i)
	{
		new_command[k] = all->her_str[k];
		k++;
	}
	while (all->her_str[i + env_s])
		new_command[k++] = all->her_str[i++ + env_s];
	new_command[k] = '\0';
	free(all->her_str);
	all->her_str = new_command;
}

char	*new_str_o(t_all *all, int str_s, int com_s)
{
	char	*new_str;

	new_str = (char *)malloc(sizeof(char) * (str_s + com_s + 1));
	if (new_str == NULL)
		ft_exit(all, strerror(errno));
	return (new_str);
}
