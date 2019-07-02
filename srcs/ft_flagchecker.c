/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flagchecker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhutchin <rhutchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 14:14:25 by rhutchin          #+#    #+#             */
/*   Updated: 2019/07/02 14:15:03 by rhutchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_ls.h"

 static t_flags  ft_flagchecker(char *flags)
 {
    t_flags new;

    if((flags[1] || flags[2] || flags [3])  == 'l')
        new.l = 1;
    if((flags[1] || flags[2] || flags [3])  == 'a')
        new.a = 1;
    if((flags[1] || flags[2] || flags [3])  == 'r')
        new.r = 1;
    if((flags[1] || flags[2] || flags [3])  == 'R')
        new.R = 1;
    if((flags[1] || flags[2] || flags [3])  == 't')
        new.t = 1;
    return(new);
 }
