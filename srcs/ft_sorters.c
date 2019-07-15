/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhutchin <rhutchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 10:59:48 by rhutchin          #+#    #+#             */
/*   Updated: 2019/07/15 13:36:52 by rhutchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void	ft_timeswap(t_file **head)
{
	t_file	*scan1;
	t_file	*scan2;
	t_file	*scanner;

	scanner = *head;
	while (scanner != NULL)
	{
		scan1 = scanner;
		scan2 = scan1->next;
		if (scan2 == NULL)
			break ;
		if ((ft_strcmp(scan1->time, scan2->time) == 0) && scan1->file_name\
														< scan2->file_name)
			ft_nodeswap(&scan1, &scan2, head, &scanner);
		else
			scanner = scanner->next;
	}
}

void		ft_nodeswap(t_file **scan1, t_file **scan2, t_file **head, \
t_file **scanner)
{
	t_file *temp;

	if ((*scan1)->previous)
		(*scan1)->previous->next = (*scan2);
	(*scan2)->previous = (*scan1)->previous;
	if ((*scan2)->next)
		(*scan2)->next->previous = (*scan1);
	(*scan1)->next = (*scan2)->next;
	(*scan1)->previous = (*scan2);
	(*scan2)->next = (*scan1);
	temp = (*scan1);
	(*scan1) = (*scan2);
	if ((*scan2)->previous == NULL)
		*head = *scan2;
	(*scan2) = temp;
	*scanner = *head;
}

void		ft_sortlist(t_file **head)
{
	t_file	*scan1;
	t_file	*scan2;
	t_file	*scanner;

	scanner = *head;
	while (scanner != NULL)
	{
		scan1 = scanner;
		scan2 = scan1->next;
		if (scan2 == NULL)
			break ;
		if ((ft_strcmp(scan1->file_name, scan2->file_name)) > 0)
			ft_nodeswap(&scan1, &scan2, head, &scanner);
		else
			scanner = scanner->next;
	}
}

void		ft_revlist(t_file **head)
{
	t_file	*scan1;
	t_file	*scan2;
	t_file	*scanner;

	scanner = *head;
	while (scanner != NULL)
	{
		scan1 = scanner;
		scan2 = scan1->next;
		if (scan2 == NULL)
			break ;
		if ((ft_strcmp(scan1->file_name, scan2->file_name)) < 0)
			ft_nodeswap(&scan1, &scan2, head, &scanner);
		else
			scanner = scanner->next;
	}
}

void		ft_sortlisttime(t_file **head)
{
	t_file	*scan1;
	t_file	*scan2;
	t_file	*scanner;

	scanner = *head;
	while (scanner != NULL)
	{
		scan1 = scanner;
		scan2 = scan1->next;
		if (scan2 == NULL)
			break ;
		if ((scan1->rawtime - scan2->rawtime) < 0)
			ft_nodeswap(&scan1, &scan2, head, &scanner);
		else
			scanner = scanner->next;
	}
	ft_timeswap(head);
}
