/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhutchin <rhutchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 09:11:50 by rhutchin          #+#    #+#             */
/*   Updated: 2019/07/03 14:35:33 by rhutchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_ls.h"

void    ft_ls(int ac, char **av)
{
    t_file  *head = ft_newnode();
    t_flags flags;

    flags.flags = ft_flagchecker(ac, av);
    ft_listbuilder(flags, head);
    printf("||----Got into printer----||\n\n");//------------------------------remember to kill
    ft_listprinter(head);
    printf("\n||----Got out of printer--||\n");//------------------------------remember to kill
}