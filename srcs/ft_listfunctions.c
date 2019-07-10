/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listfunctions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhutchin <rhutchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 10:23:08 by rhutchin          #+#    #+#             */
/*   Updated: 2019/07/10 13:08:25 by rhutchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_ls.h"

t_file  *ft_newnode()
{
    t_file     *new;

    new = malloc(sizeof(t_file));
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

void    ft_addnode(t_file *node, char *file_name, struct stat stats)
{
	t_file  *new;

	new = malloc(sizeof(t_file));
	new->attributes = ft_convertAtt(stats);
	new->file_name = ft_strdup(file_name);
	new->links = stats.st_nlink;
	new->userID = ft_convertUID(stats);
	new->groupID = ft_convertGID(stats);
	new->size = stats.st_size;
	new->rawtime = stats.st_mtime;
	ft_convertTime(new);
	new->next = NULL;
	new->previous = node;
	node->next = new;
}

void	ft_dellist(t_file *head)
{
	t_file	*scanner = head;
	t_file	*tmp;

	while(scanner != NULL)
	{
		tmp = scanner->next;
		ft_strdel(&scanner->attributes);
		ft_strdel(&scanner->file_name);
		scanner->links = 0;
		ft_strdel(&scanner->userID);
		ft_strdel(&scanner->groupID);
		scanner->time = 0;
		ft_strdel(&scanner->day);
		ft_strdel(&scanner->month);
		ft_strdel(&scanner->year);
		ft_strdel(&scanner->time);
		scanner->previous = NULL;
		scanner->next = NULL;
		scanner = tmp;
	}
}
