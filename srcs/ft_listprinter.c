/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listprinter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhutchin <rhutchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 14:16:47 by rhutchin          #+#    #+#             */
/*   Updated: 2019/07/03 14:35:22 by rhutchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_ls.h"

void    ft_listprinter(t_file *head)
{
    t_file  *scanner;
    scanner = head->next;
    while(scanner != NULL)
        {
            printf("%s ", scanner->file_name);
            scanner = scanner->next;
        }
        printf("\n");
}