/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsengine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhutchin <rhutchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 14:28:20 by rhutchin          #+#    #+#             */
/*   Updated: 2019/07/16 10:12:15 by rhutchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void	ft_recurseengine(t_file **head, char *path, int flags)
{
	t_file	*scanner;
	char	*tmppath;
	char	*fullpath;

	scanner = *head;
	while (scanner != NULL)
	{
		if (scanner->attributes[0] == 'd' &&\
		!ft_strequ(scanner->file_name, ".") &&\
		!ft_strequ(scanner->file_name, ".."))
		{
			if (!(ft_strcmp(path, "/")))
				tmppath = ft_strdup("/");
			else
				tmppath = ft_strjoin(path, "/");
			fullpath = ft_strjoin(tmppath, scanner->file_name);
			printf("\n%s:\n", fullpath);
			ft_lsengine(flags, fullpath);
			ft_strdel(&tmppath);
			ft_strdel(&fullpath);
		}
		scanner = scanner->next;
	}
}

void		ft_lsengine(int flags, char *path)
{
	t_file			*head;
	size_t			minwidth;

	head = NULL;
	minwidth = 0;
	ft_readandbuild(flags, path, &head, &minwidth);
	ft_sortlist(&head, flags);
	ft_listprinter(head, (minwidth + 1), flags, path);
	if (flags & FLAG_RECURSE)
		ft_recurseengine(&head, path, flags);
	ft_dellist(&head);
}
