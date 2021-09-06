/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsadie <bsadie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 12:18:27 by bsadie            #+#    #+#             */
/*   Updated: 2021/09/06 13:10:17 by bsadie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_pwd(void)
{
	char	*buf;
	
	buf = NULL;
	buf = getcwd(buf, 0);
	if (buf)
	{
		printf("%s\n", buf);
		free (buf);
	}
	else
	{
		printf("minishell: pwd: %s\n", strerror(errno));
		return (1);
	}
	return (0);
}
