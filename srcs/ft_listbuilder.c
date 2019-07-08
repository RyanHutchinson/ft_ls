/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listbuilder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhutchin <rhutchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 14:28:20 by rhutchin          #+#    #+#             */
/*   Updated: 2019/07/08 11:10:08 by rhutchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_ls.h"

size_t   ft_listbuilder(t_flags flags, t_file *head, DIR *dr)
{
	struct dirent   *de;  //----------------------------------------------------- Pointer to the struct which will store the filename.
	struct stat     stats; //------------------------------------------------------ Making a struct which stores the current files stats (user, time, type, permissions etc.)
	t_file          *scanner = head;
	size_t          minwidth = 0;

	if (dr == NULL) //--------------------------------------------------------- Breaks when nothing 
		printf("The bad has happened -_- you are nowhere\n" ); 
	while ((de = readdir(dr)) != NULL) 
	{
		lstat(de->d_name, &stats);
		if(de->d_name[0] == '.' && !(flags.flags & 2))
		{
			continue;
		}
		else if((flags.flags & 4) && S_ISDIR(stats.st_mode))
		{
			printf("found a dir\n");
			ft_addnode(scanner, de->d_name, stats);
			scanner = scanner->next;

			if(strlen(de->d_name) > minwidth)
			minwidth = strlen(de->d_name);

			// DIR *drr = opendir("");
			//ft_listbuilder(flags, some head , drr);
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
	/*------------------------------------------------------------------------------------------*/  printf("");//-so ya... this printf keeps everything together somehow? Don't delete
	if(flags.flags & 8)
	{
		ft_revlist(head);
	}
	if(flags.flags & 16)
	{
		//make a listtimesort
	}
	closedir(dr);
	return(minwidth + 1);
}
