/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listbuilder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhutchin <rhutchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 14:28:20 by rhutchin          #+#    #+#             */
/*   Updated: 2019/07/09 16:13:08 by rhutchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_ls.h"

void   ft_listbuilder(int flags, char *path)
{
	DIR				*dr = opendir(path);  //------------------------------------------------ returns a DIR pointer.
	t_file  		*head = ft_newnode();
	struct dirent   *de;  //----------------------------------------------------- Pointer to the struct which will store the filename.
	struct stat     stats; //------------------------------------------------------ Making a struct which stores the current files stats (user, time, type, permissions etc.)
	t_file          *scanner = head;
	size_t          minwidth = 0;

	if (dr == NULL) //--------------------------------------------------------- Breaks when nothing 
		printf("The bad has happened -_- you are nowhere\n" ); 
	while ((de = readdir(dr)) != NULL) 
	{
		char *tmp = ft_strjoin(path, "/");//-------------------------fix this placement bullshit
		lstat(ft_strjoin(tmp, de->d_name), &stats);
		if(de->d_name[0] == '.' && !(flags & 2))
		{
			continue;
		}
		else
		{
			ft_addnode(scanner, de->d_name, stats);
			scanner = scanner->next;

			if(strlen(de->d_name) > minwidth)
			minwidth = strlen(de->d_name);
		}
	}
	ft_sortlist(head);
	/*------------------------------------------------------------------------------------------*///  printf("");//-so ya... this printf keeps everything together somehow? Don't delete
	if(flags & 16)
		ft_sortlisttime(head);
	if(flags & 8)
		ft_revlist(head);
	ft_listprinter(head, (minwidth + 1), flags);
	if(flags & 4)
		{
			scanner = head->next;
			while(scanner != NULL)
			{
				if(scanner->file_name[0] == '.')
				{
					continue;
				}
				else if(scanner->attributes[0] == 'd')
				{
					printf("\n./%s:\n\n", scanner->file_name);
					ft_listbuilder(flags, scanner->file_name);
				}
				scanner = scanner->next;
			}
		}
		ft_dellist(head);
		closedir(dr);
}
