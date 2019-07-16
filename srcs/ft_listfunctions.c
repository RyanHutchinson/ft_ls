/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listfunctions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhutchin <rhutchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 10:23:08 by rhutchin          #+#    #+#             */
/*   Updated: 2019/07/16 11:11:22 by rhutchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_file		*ft_newnode(char *file_name, struct stat stats)
{
	t_file	*new;

	new = malloc(sizeof(t_file));
	new->attributes = ft_convertatt(stats);
	new->file_name = ft_strdup(file_name);
	new->links = stats.st_nlink;
	new->blocks = stats.st_blocks;
	new->userid = ft_convertuid(stats);
	new->groupid = ft_convertgid(stats);
	new->size = stats.st_size;
	new->rawtime = stats.st_mtime;
	ft_converttime(new);
	new->next = NULL;
	new->previous = NULL;
	return (new);
}

t_file		*ft_addnode(t_file *head, char *file_name, struct stat stats)
{
	t_file	*scanner;
	t_file	*new;

	scanner = head;
	new = ft_newnode(file_name, stats);
	if (head == NULL)
		return (new);
	else
	{
		while (scanner->next != NULL)
			scanner = scanner->next;
		scanner->next = new;
		new->previous = scanner;
	}
	return (head);
}

static void	ft_delnode(t_file *node)
{
	ft_strdel(&node->attributes);
	ft_strdel(&node->file_name);
	node->links = 0;
	node->blocks = 0;
	ft_strdel(&node->userid);
	ft_strdel(&node->groupid);
	node->size = 0;
	node->rawtime = 0;
	ft_strdel(&node->day);
	ft_strdel(&node->month);
	ft_strdel(&node->year);
	ft_strdel(&node->time);
	node->next = NULL;
	node->previous = NULL;
	free(node);
}

void		ft_dellist(t_file **head)
{
	t_file	*scanner;
	t_file	*next;

	scanner = *head;
	while (scanner != NULL)
	{
		next = scanner->next;
		ft_delnode(scanner);
		scanner = next;
	}
}
