/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhutchin <rhutchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 09:11:50 by rhutchin          #+#    #+#             */
/*   Updated: 2019/07/04 16:01:33 by rhutchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_ls.h"

void    ft_ls(int ac, char **av)
{
    t_file  *head = ft_newnode();
    t_flags flags;
    size_t     minwidth;
    DIR *dr = opendir(".");  //------------------------------------------------ returns a DIR pointer.

    flags.flags = ft_flagchecker(ac, av);
    minwidth = ft_listbuilder(flags, head, dr);
    ft_listprinter(head, minwidth);
}