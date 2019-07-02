/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listbuilder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhutchin <rhutchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 14:28:20 by rhutchin          #+#    #+#             */
/*   Updated: 2019/07/02 14:28:59 by rhutchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_ls.h"

t_file   *ft_listbuilder(t_flags flags)
{
    struct dirent *de;  //----------------------------------------------------- Pointer to the struct which will store the filename.
    struct stat file_info; //-------------------------------------------------- Making a struct which stores the current files stats (user, time, type, permissions etc.)
    struct t_file *file_list_head;

    DIR *dr = opendir(".");  //------------------------------------------------ returns a DIR pointer.
  
    if (dr == NULL) //--------------------------------------------------------- Breaks when nothing 
        printf("The bad has happened -_- you are nowhere\n" ); 

    while ((de = readdir(dr)) != NULL) 
    {
        lstat(de->d_name, &file_info);
        ft_addnode(&file_list_head, de->d_name, file_info);

        if (file_info.st_mode == S_IFDIR)//------------------------------------ Do the stuff
            {
            /*Damnit. Think a little cleaner */
            }
        else
            {
            /* code */
            }
        
    }
    closedir(dr);
    return(file_list_head);
}