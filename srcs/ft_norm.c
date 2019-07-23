/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_norm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhutchin <rhutchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 13:09:05 by rhutchin          #+#    #+#             */
/*   Updated: 2019/07/23 13:14:28 by rhutchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	ft_printiterator(t_file **scanner, int flags, char *path, int *padding)
{
	while (*scanner != NULL)
	{
		if (flags & FLAG_L)
		{
			ft_longprinter(*scanner, path, padding);
			*scanner = (*scanner)->next;
		}
		else
		{
			ft_putstr((*scanner)->file_name);
			ft_putchar('\n');
			*scanner = (*scanner)->next;
		}
	}
}
