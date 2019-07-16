/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhutchin <rhutchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 09:11:50 by rhutchin          #+#    #+#             */
/*   Updated: 2019/07/16 11:35:07 by rhutchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	ft_ls(int ac, char **av)
{
	t_dirs	*dirs;
	int		flags;
	t_dirs	*scanner;

	flags = 0;
	dirs = NULL;
	dirs = ft_argparser(ac, av, &dirs, &flags);
	scanner = dirs;
	if (scanner != NULL)
	{
		while (scanner != NULL)
		{
			printf("%s:\n", scanner->dirname);//-------------------------- Printf
			ft_lsengine(flags, scanner->dirname);
			printf("\n");//-------------------------------------------- Printf
			scanner = scanner->next;
		}
	}
	else
		ft_lsengine(flags, ".");
	ft_dirsdel(&dirs);
	sleep(60);
}
