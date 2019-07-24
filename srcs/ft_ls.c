/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhutchin <rhutchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 09:11:50 by rhutchin          #+#    #+#             */
/*   Updated: 2019/07/24 09:53:59 by rhutchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void	ft_dirsengine(t_dirs **scanner, int flags)
{
	DIR		*dr;

	while (*scanner != NULL)
	{
		dr = opendir((*scanner)->dirname);
		if (errno == 0)
		{
			ft_putstr((*scanner)->dirname);
			ft_putstr(":\n");
			ft_lsengine(flags, (*scanner)->dirname);
			closedir(dr);
		}
		else if (errno == 20)
			ft_lsengine(flags, (*scanner)->dirname);
		else if (errno == 13)
			ft_lserror(3, (*scanner)->dirname);
		else if (errno == 2)
		{
			ft_lserror(2, (*scanner)->dirname);
			errno = 0;
		}
		if ((*scanner)->next)
			ft_putchar('\n');
		*scanner = (*scanner)->next;
	}
}

int			main(int ac, char **av)
{
	t_dirs	*dirs;
	int		flags;
	t_dirs	*scanner;

	flags = 0;
	dirs = NULL;
	dirs = ft_argparser(ac, av, &dirs, &flags);
	scanner = dirs;
	if (scanner != NULL)
		ft_dirsengine(&scanner, flags);
	else
		ft_lsengine(flags, ".");
	ft_dirsdel(&dirs);
	return (0);
}
