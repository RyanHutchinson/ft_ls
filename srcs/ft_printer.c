/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhutchin <rhutchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 14:16:47 by rhutchin          #+#    #+#             */
/*   Updated: 2019/07/23 13:14:44 by rhutchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"
#include "stdio.h"

static int	*ft_padding(t_file **head)
{
	t_file	*scanner;
	int		*padding;

	padding = malloc(sizeof(int) * 4);
	padding[0] = 0;
	padding[1] = 0;
	padding[2] = 0;
	padding[3] = 0;
	scanner = *head;
	while (scanner != NULL)
	{
		if (padding[0] < (int)ft_intlen(scanner->links))
			padding[0] = (int)ft_intlen(scanner->links);
		if (padding[1] < (int)ft_intlen(scanner->size))
			padding[1] = (int)ft_intlen(scanner->size);
		if (padding[2] < (int)ft_strlen(scanner->userid))
			padding[2] = (int)ft_strlen(scanner->userid);
		if (padding[3] < (int)ft_strlen(scanner->groupid))
			padding[3] = (int)ft_strlen(scanner->groupid);
		scanner = scanner->next;
	}
	return (padding);
}

static int	ft_blockcounter(t_file **head)
{
	t_file	*scanner;
	int		i;

	scanner = *head;
	i = 0;
	while (scanner != NULL)
	{
		i += scanner->blocks;
		scanner = scanner->next;
	}
	return (i);
}

static void	ft_linkprint(char *path, t_file *ptr)
{
	char		buffer[65];
	char		*tpath;
	char		*tmp;

	ft_bzero(&buffer, 65);
	tmp = ft_strjoin(path, "/");
	tpath = ft_strjoin(tmp, ptr->file_name);
	ft_strdel(&tmp);
	readlink(tpath, buffer, 64);
	ft_putstr(" -> ");
	ft_putstr(buffer);
	ft_putchar('\n');
	ft_strdel(&tpath);
}

void		ft_longprinter(t_file *scanner, char *path, int *padding)
{
	ft_putstr(scanner->attributes);
	ft_putstr("  ");
	ft_linksprinter(scanner, padding);
	ft_useridprinter(scanner, padding);
	ft_groupidprinter(scanner, padding);
	ft_sizeprinter(scanner, padding);
	ft_dayprinter(scanner);
	ft_putstr(scanner->month);
	ft_putstr(" ");
	ft_putstr(scanner->time);
	ft_putstr(" ");
	if (scanner->attributes[0] == 'l')
	{
		ft_putstr(scanner->file_name);
		ft_linkprint(path, scanner);
	}
	else
	{
		ft_putstr(scanner->file_name);
		ft_putchar('\n');
	}
}

void		ft_listprinter(t_file *head, int flags, char *path)
{
	t_file	*scanner;
	int		i;
	int		*padding;

	padding = ft_padding(&head);
	i = ft_blockcounter(&head);
	scanner = head;
	if ((flags & FLAG_L) && i != 0)
	{
		ft_putstr("total ");
		ft_putnbr(i);
		ft_putchar('\n');
	}
	ft_printiterator(&head, flags, path, padding);
	free(padding);
}
