/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhutchin <rhutchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 09:11:50 by rhutchin          #+#    #+#             */
/*   Updated: 2019/07/17 10:38:54 by rhutchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	ft_ls(int ac, char **av)
{
	t_dirs	*dirs;
	int		flags;
	t_dirs	*scanner;
	DIR		*dr;

	flags = 0;
	dirs = NULL;
	dirs = ft_argparser(ac, av, &dirs, &flags);
	scanner = dirs;
	if (scanner != NULL)
	{
		while (scanner != NULL)
		{
			dr = opendir(scanner->dirname);
			if (errno == 0)
				printf("%s:\n", scanner->dirname);//-------------------------- Printf
			else if (errno == 13)
			{
				printf("Permission denied for: %s\n", scanner->dirname);
				exit(0);
			}
			if (errno == 0)
				closedir(dr);
			ft_lsengine(flags, scanner->dirname);
			printf("\n");//-------------------------------------------- Printf
			scanner = scanner->next;
		}
	}
	else
		ft_lsengine(flags, ".");
	ft_dirsdel(&dirs);
}
