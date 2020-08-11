/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chgilber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 17:17:15 by chgilber          #+#    #+#             */
/*   Updated: 2020/08/06 19:02:11 by chgilber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		cdnoarg(int i)
{
	int		a;
	char	*path;

	i = 0;
	a = 0;
	path = NULL;
	path = getcwd(path, 0);
	while (path[i] && a != 3)
	{
		if (path[i] == '/')
			a++;
		i++;
	}
	//	printf("(%s)%d{%s}\n" , path,i, ft_substr(path, 0, i - 1));
	i = chdir(ft_substr(path, 0, i - 1));
//	i = chdir("$HOME");
	return (i);
}

int		cd(char **dir)
{
	int		i;

	i = 0;
	if (dir[1])
	{
		i = chdir((dir[1]));
		if (i == -1)
		{
			write(1, "bash: cd: ", 10);
			write(1, dir[1], ft_strlen(dir[1]));
			write(1, ": No such file or directory\n", 28);
		}
	}
	else
		i = cdnoarg(i);
	return (i);
}
