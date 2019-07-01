/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhutchin <rhutchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 09:11:50 by rhutchin          #+#    #+#             */
/*   Updated: 2019/07/01 09:46:01 by rhutchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./incl/ft_ls.h"
#include <dirent.h> //--------------------------------------------------------- Makes the DIR opening, closing and reading magic happen.
#include <stdio.h> //---------------------------------------------------------- Delete me mc cheaty

static void ft_reader()
{
    struct dirent *de;  //----------------------------------------------------- Pointer to the struct which will store the filename.
    
    DIR *dr = opendir(".");  //------------------------------------------------- returns a DIR pointer.
  
    if (dr == NULL) //--------------------------------------------------------- Breaks when nothing 
    { 
        printf("Could not open current directory" ); 
    } 

    while ((de = readdir(dr)) != NULL) 
    {

            printf("%s\n", de->d_name);
    }
  
    closedir(dr);
}

int main (void)
{
    ft_reader();
    return (0);    
}