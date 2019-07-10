/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhutchin <rhutchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 09:11:50 by rhutchin          #+#    #+#             */
/*   Updated: 2019/07/10 13:12:06 by rhutchin         ###   ########.fr       */
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
			printf("%s:\n", dirs->dirname);
			ft_listbuilder(flags, ft_strjoin(path, dirs->dirname));
			printf("\n");
			dirs = dirs->next;
		}
	}
	else
		ft_listbuilder(flags, ".");
}
