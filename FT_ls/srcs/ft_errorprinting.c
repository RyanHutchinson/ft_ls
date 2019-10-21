/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errorprinting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhutchin <rhutchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 12:57:47 by rhutchin          #+#    #+#             */
/*   Updated: 2019/07/17 14:54:29 by rhutchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	ft_lserror(int error, char *str)
{
	if (error == 1)
	{
		ft_putstr("Invalid flag - ");
		ft_putchar(str[0]);
		ft_putstr("\nft_ls usage is: [-alRrt] [file...]\n");
		exit(0);
	}
	if (error == 2)
	{
		ft_putstr(str);
		ft_putstr(" is not a valid Directory");
		ft_putstr("\n");
	}
	if (error == 3)
	{
		ft_putstr("Permission denied for : ");
		ft_putstr(str);
		ft_putchar('\n');
		errno = 0;
	}
}
