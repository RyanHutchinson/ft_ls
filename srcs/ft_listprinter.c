/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listprinter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhutchin <rhutchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 14:16:47 by rhutchin          #+#    #+#             */
/*   Updated: 2019/07/11 09:21:24 by rhutchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_ls.h"

static long ft_blockcounter(t_file **head)
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

void	ft_listprinter(t_file *head, size_t minwidth, int flags)
{
	t_file	*scanner;
	long	i;
	
	i = ft_blockcounter(&head);
	scanner = head;
	if (flags & FLAG_L)
		printf("total %ld\n", i);//-------------------------------------------- Printf
	while (scanner != NULL)
		{
			if (flags & FLAG_L)
			{
				printf("%s ", scanner->attributes);//-------------------------- Printf
				printf("%3d ", scanner->links);//------------------------------ Printf
				printf("%s  ", scanner->userID);//----------------------------- Printf
				printf("%s  ", scanner->groupID);//---------------------------- Printf
				printf("%5d ", scanner->size);//------------------------------- Printf
				printf("%2s ", scanner->day);//-------------------------------- Printf
				printf("%s ", scanner->month);//------------------------------- Printf
				printf("%s ", scanner->time);//-------------------------------- Printf
				printf("%s\n", scanner->file_name);//-------------------------- Printf
				scanner = scanner->next;
			}
			else
			{
				printf("%-*s", (int)minwidth, scanner->file_name);//----------- Printf
				scanner = scanner->next;
			}
		}
		if(!(flags & FLAG_L))
			printf("\n");//---------------------------------------------------- Printf
}
