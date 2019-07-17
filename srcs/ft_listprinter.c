/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listprinter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhutchin <rhutchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 14:16:47 by rhutchin          #+#    #+#             */
/*   Updated: 2019/07/17 13:53:09 by rhutchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static	long	ft_blockcounter(t_file **head)
{
	t_file	*scanner;
	long	i;

	scanner = *head;
	i = 0;
	while (scanner != NULL)
	{
		i += scanner->blocks;
		scanner = scanner->next;
	}
	return (i);
}

static void		ft_linkprint(char *path, t_file *ptr)
{
	char		buffer[65];
	char		*tpath;
	char		*tmp;

	ft_bzero(&buffer, 65);
	tmp = ft_strjoin(path, "/");
	tpath = ft_strjoin(tmp, ptr->file_name);
	ft_strdel(&tmp);
	readlink(tpath, buffer, 64);
	printf(" -> %s\n", buffer);
	ft_strdel(&tpath);
}

static	void	ft_longprinter(t_file *scanner, char *path)
{
	printf("%s ", scanner->attributes);//-------------------------- Printf
	printf("%3d ", scanner->links);//------------------------------ Printf
	printf("%s  ", scanner->userid);//----------------------------- Printf
	printf("%s  ", scanner->groupid);//---------------------------- Printf
	printf("%5d ", scanner->size);//------------------------------- Printf
	printf("%2s ", scanner->day);//-------------------------------- Printf
	printf("%s ", scanner->month);//------------------------------- Printf
	printf("%s ", scanner->time);//-------------------------------- Printf
	if (scanner->attributes[0] == 'l')
	{
		printf("%s", scanner->file_name);
		ft_linkprint(path, scanner);
	}
	else
		printf("%s\n", scanner->file_name);//-------------------------- Printf
}

void			ft_listprinter(t_file *head, int flags, char *path)
{
	t_file	*scanner;
	long	i;

	i = ft_blockcounter(&head);
	scanner = head;
	if ((flags & FLAG_L) && i != 0)
		printf("total %ld\n", i);//-------------------------------- Printf
	while (scanner != NULL)
	{
		if (flags & FLAG_L)
		{
			ft_longprinter(scanner, path);
			scanner = scanner->next;
		}
		else
		{
			printf("%s\n", scanner->file_name);// Printf
			scanner = scanner->next;
		}
	}
}
