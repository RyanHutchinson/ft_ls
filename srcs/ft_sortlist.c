/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sortlist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhutchin <rhutchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 10:33:23 by rhutchin          #+#    #+#             */
/*   Updated: 2019/07/02 10:48:34 by rhutchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_ls.h"

void    ft_sortlist(t_file *list)
{
    t_file  *scanner;
    int     i;

    scanner = list;
    while((i = strcmp(scanner->file_name, scanner->next->file_name)) < 0)
        {
            
        }
}