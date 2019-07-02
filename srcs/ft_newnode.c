/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newnode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhutchin <rhutchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 10:13:22 by rhutchin          #+#    #+#             */
/*   Updated: 2019/07/02 10:48:31 by rhutchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_ls.h"

t_file  *ft_newnode(char *file_name, struct dirent *de)
{
    t_file     *new;

    new = mallock(sizeof(t_file));
    new->file_name = ft_strdup(file_name);
    new->de = de;
    new->next = NULL;
    new->previous = NULL;
    return(new);
}