/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listprinter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhutchin <rhutchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 14:16:47 by rhutchin          #+#    #+#             */
/*   Updated: 2019/07/08 12:54:16 by rhutchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_ls.h"

void    ft_listprinter(t_file *head, size_t minwidth, t_flags flags)
{
	t_file  *scanner;
	scanner = head->next;
	while(scanner != NULL)
		{
			if(flags.flags & 1)
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
	if(!(flags.flags & 1))
		printf("\n");
}