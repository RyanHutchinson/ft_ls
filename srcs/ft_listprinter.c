/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listprinter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhutchin <rhutchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 14:16:47 by rhutchin          #+#    #+#             */
/*   Updated: 2019/07/17 15:58:34 by rhutchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

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
	printf(" -> %s\n", buffer);
	ft_strdel(&tpath);
}

static void	ft_longprinter(t_file *scanner, char *path, t_file **head)
{
	ft_putstr(scanner->attributes);
	ft_putstr("  ");
	ft_linksprinter(scanner, head);
	ft_putstr(scanner->userid);
	ft_putstr("  ");
	ft_putstr(scanner->groupid);
	ft_putstr("  ");
	ft_sizeprinter(scanner, head);
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

	i = ft_blockcounter(&head);
	scanner = head;
	if ((flags & FLAG_L) && i != 0)
	{
		ft_putstr("total ");
		ft_putnbr(i);
		ft_putchar('\n');
	}
	while (scanner != NULL)
	{
		if (flags & FLAG_L)
		{
			ft_longprinter(scanner, path, &head);
			scanner = scanner->next;
		}
		else
		{
			ft_putstr(scanner->file_name);
			ft_putchar('\n');
			scanner = scanner->next;
		}
	}
}
