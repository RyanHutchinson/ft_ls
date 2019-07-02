/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newnode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhutchin <rhutchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 10:13:22 by rhutchin          #+#    #+#             */
/*   Updated: 2019/07/02 12:00:32 by rhutchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_ls.h"

t_file  *ft_newnode(char *file_name, struct stat file_info)
{
    t_file     *new;

    new = mallock(sizeof(t_file));
    new->file_name = ft_strdup(file_name);
    new->file_info = file_info;
    new->next = NULL;
    new->previous = NULL;
    return(new);
}