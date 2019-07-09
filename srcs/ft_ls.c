/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhutchin <rhutchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 09:11:50 by rhutchin          #+#    #+#             */
/*   Updated: 2019/07/09 16:16:11 by rhutchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_ls.h"

void    ft_ls(int ac, char **av)
{
	t_dirs	*dirs = NULL;
	int 	flags = 0;
	char	*path = "./";
	int i;

	i = ft_flagchecker(ac, av, dirs, &flags, path);
	if(dirs!= NULL)
		while(dirs != NULL)
		{
			ft_listbuilder(flags, path);
		}
	else
		ft_listbuilder(flags, path);
	printf("%d\n", i);
}