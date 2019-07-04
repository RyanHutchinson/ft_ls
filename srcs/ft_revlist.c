/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_revlist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhutchin <rhutchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 10:33:23 by rhutchin          #+#    #+#             */
/*   Updated: 2019/07/04 15:15:23 by rhutchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_ls.h"

// ********************************************************************************
// ********************************************************************************
// ********************************************************************************
// Remember that you need this to norm so make a static helper... You did try this
// but it kept breaking and behaving incorrectly. I'm sure you can figure this out
// future me.
// ********************************************************************************
// ********************************************************************************
// ********************************************************************************


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