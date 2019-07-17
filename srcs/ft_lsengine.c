/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsengine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhutchin <rhutchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 14:28:20 by rhutchin          #+#    #+#             */
/*   Updated: 2019/07/17 13:41:59 by rhutchin         ###   ########.fr       */
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
			ft_putchar('\n');
			ft_putstr(fullpath);
			ft_putchar('\n');
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

	head = NULL;
	ft_readandbuild(flags, path, &head);
	ft_sortlist(&head, flags);
	ft_listprinter(head, flags, path);
	if (flags & FLAG_RECURSE)
		ft_recurseengine(&head, path, flags);
	ft_dellist(&head);
}
