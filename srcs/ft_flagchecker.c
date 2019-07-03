/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flagchecker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhutchin <rhutchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 14:14:25 by rhutchin          #+#    #+#             */
/*   Updated: 2019/07/03 08:30:09 by rhutchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_ls.h"

 unsigned char		ft_flagchecker(int ac, char **av)
{
	int				i;
	char			**str;
	unsigned char	flags;

	flags = 0;
	i = 1;
	while (i < ac)
	{
		str = &av[i];
		while (**str == 'l' || **str == 'a' || **str == 'R' ||
			**str == 'r' || **str == 't' || **str == ' ' || **str == '-')
		{
			if (**str == 'l')
				flags |= 1;
			if (**str == 'a')
				flags |= 2;
			if (**str == 'R')
				flags |= 4;
			if (**str == 'r')
				flags |= 8;
			if (**str == 't')
				flags |= 16;
			(*str)++;
		}
		i++;
	}
	return (flags);
}