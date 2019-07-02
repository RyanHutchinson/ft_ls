/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhutchin <rhutchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 10:44:13 by rhutchin          #+#    #+#             */
/*   Updated: 2019/07/02 15:13:16 by rhutchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include "../libft/libft.h"
#include <dirent.h>     //----------------------------------------------------- Makes the DIR opening, closing and reading magic happen.
#include <sys/stat.h>   //----------------------------------------------------- Makes checking for file stats happen...
#include <sys/types.h>  //----------------------------------------------------- Makes various types available for use...
#include <stdio.h>      //----------------------------------------------------- Delete me mc cheaty

typedef	struct		s_file
{
    char			*file_name;
    struct stat		file_info;
    struct s_file	*next;
    struct s_file	*previous;
}                   t_file;

typedef	struct		s_flags
{
    unsigned char   flags;
}                   t_flags;

void		    ft_ls(int ac, char **av);

t_file		    *ft_listbuilder(t_flags flags);
unsigned char	ft_flagchecker(char **av, int ac);
void		    ft_listprinter(t_file *file_list_head);

t_file		    *ft_newnode(char *file_name, struct stat file_info);
void		    ft_addnode(t_file *node, char *file_name, struct stat file_info);
void		    ft_sortlist(t_file *list);

#endif
