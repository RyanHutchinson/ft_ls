/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addnode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhutchin <rhutchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 10:23:08 by rhutchin          #+#    #+#             */
/*   Updated: 2019/07/03 10:47:28 by rhutchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_ls.h"

void    ft_addnode(t_file *node, char *file_name)
{
    t_file  *new;

    new = ft_newnode();
    new->file_name = file_name;
    new->file_info = NULL;
    new->next = NULL;
    new->previous = node;
    node->next = new;
}