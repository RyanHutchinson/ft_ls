/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhutchin <rhutchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 09:11:50 by rhutchin          #+#    #+#             */
/*   Updated: 2019/07/02 15:13:35 by rhutchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./incl/ft_ls.h"

void    ft_ls(int ac, char **av)
{
    t_file  *file_list_head;
    t_flags flags;

    flags.flags = ft_flagchecker(ac, av);
    file_list_head = ft_listbuilder(flags);
    ft_listprinter(file_list_head);
}