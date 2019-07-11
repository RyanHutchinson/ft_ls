/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhutchin <rhutchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 09:11:50 by rhutchin          #+#    #+#             */
/*   Updated: 2019/07/11 08:49:37 by rhutchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_ls.h"

void	ft_ls(int ac, char **av)
{
	t_dirs	*dirs;
	int		flags;
	char	*path;

	flags = 0;
	path = "";
	dirs = NULL;
	dirs = ft_argparser(ac, av, dirs, &flags);
	if (dirs != NULL)
	{
		while (dirs != NULL)
		{
			printf("%s:\n", dirs->dirname);//---------------------------------- Printf
			ft_lsengine(flags, ft_strjoin(path, dirs->dirname));
			printf("\n");//---------------------------------------------------- Printf
			dirs = dirs->next;
		}
	}
	else
		ft_lsengine(flags, ".");
}
