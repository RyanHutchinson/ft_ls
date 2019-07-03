/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newnode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhutchin <rhutchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 10:13:22 by rhutchin          #+#    #+#             */
/*   Updated: 2019/07/03 09:13:07 by rhutchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_ls.h"

t_file  *ft_newnode()
{
    t_file     *new;

    new = (t_file *)malloc(sizeof(t_file));
    new->file_name = NULL;
    new->file_info = NULL;
    new->next = NULL;
    new->previous = NULL;
    return(new);
}