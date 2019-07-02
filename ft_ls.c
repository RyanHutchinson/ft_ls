/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhutchin <rhutchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 09:11:50 by rhutchin          #+#    #+#             */
/*   Updated: 2019/07/02 12:16:10 by rhutchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./incl/ft_ls.h"

static  void    ft_printer(struct t_file *file_list_head, char *flags)
{
    //does a bunch of flag checks and prints the list accordingly.
}

static t_file   *ft_listbuilder()
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

        if (file_info.st_mode != S_IFDIR)//------------------------------------ Do the stuff
            {}
    }
    closedir(dr);
    return(file_list_head);
}

static  void    ft_ls(char **av)
{
    t_file  *file_list_head;

    file_list_head = ft_listbuilder();
    //ft_flagchecker(av);
    ft_printer(file_list_head, av);
    printf("\n");
}

int main (int ac, char **av)
{
    if (ac < 1)
        {
            printf("how?!?!?!?!?\n");
            return (0);
        }
    ft_ls(av);
    return (0);    
}