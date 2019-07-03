/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listbuilder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhutchin <rhutchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 14:28:20 by rhutchin          #+#    #+#             */
/*   Updated: 2019/07/03 14:35:06 by rhutchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_ls.h"

t_file   *ft_listbuilder(t_flags flags, t_file *head)
{
    struct dirent *de;  //----------------------------------------------------- Pointer to the struct which will store the filename.
 //   struct stat file_info; //-------------------------------------------------- Making a struct which stores the current files stats (user, time, type, permissions etc.)

    DIR *dr = opendir(".");  //------------------------------------------------ returns a DIR pointer.
    t_file  *scanner = head;

    if (dr == NULL) //--------------------------------------------------------- Breaks when nothing 
        printf("The bad has happened -_- you are nowhere\n" ); 
    while ((de = readdir(dr)) != NULL) 
    {
 //       lstat(de->d_name, &file_info);
        if(flags.flags & 1)
        {
            
        }
        else
        {
            ft_addnode(scanner, de->d_name);
            scanner = scanner->next;
        }
        
        // if (file_info.st_mode == S_IFDIR)//------------------------------------ Do the stuff
        //     {
        //     printf("There is a head\n");
        //     }

    }
    printf("||----Got into sortlist---||\n");//----------------------------------------remember to kill
    ft_sortlist(head);
    printf("||----Got outta sortlist--||\n");
    closedir(dr);
    return(head);
}

//      if(flags.flags & 1)