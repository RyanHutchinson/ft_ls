/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhutchin <rhutchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 10:44:13 by rhutchin          #+#    #+#             */
/*   Updated: 2019/07/04 14:45:48 by rhutchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include "../libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>     //----------------------------------------------------- Makes the DIR opening, closing and reading magic happen.
#include <sys/stat.h>   //----------------------------------------------------- Makes checking for file stats happen...
#include <sys/types.h>  //----------------------------------------------------- Makes various types available for use...
#include <stdio.h>      //----------------------------------------------------- Delete me mc cheaty

typedef	struct		s_file
{
    char			*file_name;
    struct stat		*file_info;
    struct s_file	*next;
    struct s_file	*previous;
}                   t_file;

typedef	struct		s_flags
{
    unsigned char   flags;
}                   t_flags;

void		    ft_ls(int ac, char **av);

size_t 		    ft_listbuilder(t_flags flags, t_file *head, DIR *dr);
unsigned char	ft_flagchecker(int ac, char **av);
void		    ft_listprinter(t_file *head, size_t minwidth);

t_file		    *ft_newnode();
void		    ft_addnode(t_file *node, char *file_name);
void		    ft_sortlist(t_file *head);
void            ft_revlist(t_file *head);

#endif
