/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listprinter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhutchin <rhutchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 14:16:47 by rhutchin          #+#    #+#             */
/*   Updated: 2019/07/10 13:49:17 by rhutchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_ls.h"

void    ft_listprinter(t_file *head, size_t minwidth, int flags)
{
	t_file  *scanner;
	scanner = head;
	while(scanner != NULL)
		{
			if(flags & FLAG_L)
			{
				printf("%s ", scanner->attributes);
				printf("%3d ", scanner->links);
				printf("%s  ", scanner->userID);
				printf("%s  ", scanner->groupID);
				printf("%5d ", scanner->size);
				printf("%2s ", scanner->day);
				printf("%s ", scanner->month);
				printf("%s ", scanner->time);
				printf("%s\n", scanner->file_name);
				scanner = scanner->next;
			}
			else
			{
				printf("%-*s", (int)minwidth, scanner->file_name);
				scanner = scanner->next;
			}
		}
	if(!(flags & FLAG_L))
		printf("\n");
}