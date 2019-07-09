/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flagchecker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhutchin <rhutchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 14:14:25 by rhutchin          #+#    #+#             */
/*   Updated: 2019/07/09 15:37:27 by rhutchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_ls.h"

int ft_flagchecker(int ac, char **av, t_dirs *dirs, int *flags, char *path)
{
	int i;
	char *str;

	(void)path;//-----------------------------------------------------------------delete
	(void)dirs;//-----------------------------------------------------------------delete

	i = 1;
	while (i < ac)
	{
		str = av[i];
		if (*str == '-')
		{
			str++;
			while (*str == 'l' || *str == 'a' || *str == 'R' ||
				   *str == 'r' || *str == 't')
			{
				if (*str == 'l')
					*flags |= 1;
				if (*str == 'a')
					*flags |= 2;
				if (*str == 'R')
					*flags |= 4;
				if (*str == 'r')
					*flags |= 8;
				if (*str == 't')
					*flags |= 16;
				str++;
			}
			i++;
		}
	}
	
	return (i);
}