/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addnode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhutchin <rhutchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 10:23:08 by rhutchin          #+#    #+#             */
/*   Updated: 2019/07/02 10:48:33 by rhutchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_ls.h"

void    ft_addnode(t_file *node, char *file_name, struct dirent *de)
{
    t_file  *new;

    new = ft_newnode(file_name, de);
    new->next = NULL;
    new->previous = node;
    node->next = new;
}