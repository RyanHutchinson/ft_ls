/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sortlist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhutchin <rhutchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 10:33:23 by rhutchin          #+#    #+#             */
/*   Updated: 2019/07/03 15:44:07 by rhutchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_ls.h"

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
			//printf("Got to swap: ");//------------------------------remember to kill
			// 0 -1  1
			// 1  0  2
			// 2  1  3
			// 3  2  4

			// 0 -1  2
			// 2  0  1
			// 1  2  3
			// 3  1  4


			//a->next = c;
			if (scan1->previous)
				scan1->previous->next = scan2;
			//c->previous = a;
			scan2->previous = scan1->previous;
			//d->previous = b;
			if (scan2->next)
				scan2->next->previous = scan1;
			//b->next = d;
			scan1->next = scan2->next;
			//b->previous = c;
			scan1->previous = scan2;
			//c->next = b;
			scan2->next = scan1;


			
			
			
			
			//scan1->previous = scan2;
			temp = scan1;
			scan1 = scan2;
			scan2 = temp;
			// printf("{%s >< %s}\n", scan1->file_name, scan2->file_name);
			// ft_listprinter(head);
			scanner = head->next;
		}
		else
		{
			scanner = scanner->next;
		}
	}
}
