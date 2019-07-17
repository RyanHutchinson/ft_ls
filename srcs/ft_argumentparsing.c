/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argumentparsing.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhutchin <rhutchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 14:14:25 by rhutchin          #+#    #+#             */
/*   Updated: 2019/07/17 10:34:30 by rhutchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	ft_flagsetter(int *flags, char *str)
{
	while (*str != '\0')
	{
		if (*str == 'l' || *str == 'a' || *str == 'R' || *str == 'r' \
			|| *str == 't')
		{
			if (*str == 'l')
				*flags |= FLAG_L;
			if (*str == 'a')
				*flags |= FLAG_A;
			if (*str == 'R')
				*flags |= FLAG_RECURSE;
			if (*str == 'r')
				*flags |= FLAG_R;
			if (*str == 't')
				*flags |= FLAG_T;
			str++;
		}
		else
		{
			printf("Invalid flag - %c\nft_ls usage is: [-alRrt] [file...]\n", *str);
			exit(0);
		}
	}
}

t_dirs	*ft_argparser(int ac, char **av, t_dirs **dirs, int *flags)
{
	int		i;
	char	*str;

	i = 1;
	while (i < ac)
	{
		str = av[i];
		if (*str == '-')
		{
			str++;
			ft_flagsetter(flags, str);
		}
		else
			*dirs = ft_adddir(str, *dirs);
		i++;
	}
	return (*dirs);
}
