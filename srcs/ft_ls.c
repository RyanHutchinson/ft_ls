/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhutchin <rhutchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 09:11:50 by rhutchin          #+#    #+#             */
/*   Updated: 2019/07/04 13:46:48 by rhutchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_ls.h"

void    ft_ls(int ac, char **av)
{
    t_file  *head = ft_newnode();
    t_flags flags;

    flags.flags = ft_flagchecker(ac, av);
    printf("\n\n||----Got into builder----||\n");//------------------------------remember to kill   
    ft_listbuilder(flags, head);
    printf("||----Got outta builder---||\n");//------------------------------remember to kill
    printf("||----Got into printer----||\n\n");//------------------------------remember to kill
    ft_listprinter(head);
    printf("\n||----Got outta printer---||\n");//------------------------------remember to kill
}