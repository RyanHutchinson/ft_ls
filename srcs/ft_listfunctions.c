/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listfunctions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhutchin <rhutchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 10:23:08 by rhutchin          #+#    #+#             */
/*   Updated: 2019/07/08 12:08:18 by rhutchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_ls.h"

t_file  *ft_newnode()
{
    t_file     *new;

    new = (t_file *)malloc(sizeof(t_file));
	new->attributes = NULL;
    new->file_name = NULL;
    new->links = 0;
    new->userID = NULL;
    new->groupID = NULL;
	new->size = 0;
    new->rawtime = 0;
	new->day = NULL;
	new->month = NULL;
	new->year = NULL;
	new->time = NULL;
    new->next = NULL;
    new->previous = NULL;
    return(new);
}

int    ft_addnode(t_file *node, char *file_name, struct stat stats)
{
	t_file  *new;

	if (!(new = malloc(sizeof(t_file))))
		return (0);
	
	new->attributes = ft_convertAtt(stats);
	new->file_name = file_name;
	new->links = stats.st_nlink;
	new->userID = ft_convertUID(stats);
	new->groupID = ft_convertGID(stats);
	new->size = stats.st_size;
	new->rawtime = stats.st_mtimespec.tv_sec;
	ft_convertTime(new);
	new->next = NULL;
	new->previous = node;
	node->next = new;
	return(1);
}

void    ft_sortlist(t_file *head)
{
	t_file	*scan1;
	t_file	*scan2;
	t_file	*scanner;
	t_file	*temp;
	int		i;

	scanner = head->next;
	while(scanner != NULL)
	{
		scan1 = scanner;
		scan2 = scan1->next;
		if(scan2 == NULL)
			break;
		if((i = strcmp(scan1->file_name, scan2->file_name)) > 0)
		{
			if (scan1->previous)
				scan1->previous->next = scan2;
			scan2->previous = scan1->previous;
			if (scan2->next)
				scan2->next->previous = scan1;
			scan1->next = scan2->next;
			scan1->previous = scan2;
			scan2->next = scan1;
			temp = scan1;
			scan1 = scan2;
			scan2 = temp;
			scanner = head->next;
		}
		else
		{
			scanner = scanner->next;
		}
	}
}

void    ft_revlist(t_file *head)
{
	t_file	*scan1;
	t_file	*scan2;
	t_file	*scanner;
	t_file	*temp;
	int		i;

	scanner = head->next;
	while(scanner != NULL)
	{
		scan1 = scanner;
		scan2 = scan1->next;
		if(scan2 == NULL)
			break;
		if((i = strcmp(scan1->file_name, scan2->file_name)) < 0)
		{
			if (scan1->previous)
				scan1->previous->next = scan2;
			scan2->previous = scan1->previous;
			if (scan2->next)
				scan2->next->previous = scan1;
			scan1->next = scan2->next;
			scan1->previous = scan2;
			scan2->next = scan1;
			temp = scan1;
			scan1 = scan2;
			scan2 = temp;
			scanner = head->next;
		}
		else
		{
			scanner = scanner->next;
		}
	}
}