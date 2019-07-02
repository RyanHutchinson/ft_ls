/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sortlist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhutchin <rhutchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 10:33:23 by rhutchin          #+#    #+#             */
/*   Updated: 2019/07/02 11:43:08 by rhutchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_ls.h"

void    ft_sortlist(t_file *list)
{
    t_file  *scanner;
    t_file  *temp;
    int     i;

    scanner = list;
    while(scanner->next != NULL)
    {
        if((i = strcmp(scanner->file_name, scanner->next->file_name)) > 0)
        {
            temp = scanner->next->next;
            scanner->previous->next = scanner->next;
            scanner->next->previous = scanner->previous;
            scanner->next->next = scanner;
            scanner->previous = scanner->next;
            scanner->next = temp;
        }
        else
            scanner = scanner->next;
    }
}