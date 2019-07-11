/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsengine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhutchin <rhutchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 14:28:20 by rhutchin          #+#    #+#             */
/*   Updated: 2019/07/11 11:05:01 by rhutchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_ls.h"

void   ft_lsengine(int flags, char *path)
{
	t_file  		*head = NULL;
	t_file          *scanner;
	size_t          minwidth = 0;
	char			*tmppath;
	char			*fullpath;

	ft_readandbuild(flags, path, &head, &minwidth);
	ft_sortlist(&head);
	if(flags & FLAG_T)
		ft_sortlisttime(&head);
	if(flags & FLAG_R)
		ft_revlist(&head);
	ft_listprinter(head, (minwidth + 1), flags);
	if(flags & FLAG_RECURSE)
	{
		scanner = head;
		while(scanner != NULL)
		{
			if(scanner->attributes[0] == 'd' && !ft_strequ(scanner->file_name, ".") &&
			!ft_strequ(scanner->file_name, ".."))
			{
				tmppath = ft_strjoin(path, "/");
				fullpath = ft_strjoin(tmppath, scanner->file_name);
				printf("\n./%s:\n\n", scanner->file_name);
				ft_lsengine(flags, fullpath);
				ft_strdel(&tmppath);
				ft_strdel(&fullpath);
			}
			scanner = scanner->next;
		}
	}
	ft_dellist(head);
}
