/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printerformatting.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhutchin <rhutchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 15:16:11 by rhutchin          #+#    #+#             */
/*   Updated: 2019/07/24 08:34:25 by rhutchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	ft_linksprinter(t_file *scanner, size_t *padding)
{
	int		i;

	i = padding[0] - ft_intlen(scanner->links);
	while (i > 0)
	{
		ft_putchar(' ');
		i--;
	}
	ft_putnbr(scanner->links);
	ft_putchar(' ');
}

void	ft_useridprinter(t_file *scanner, size_t *padding)
{
	int		i;

	i = padding[2] - ft_strlen(scanner->userid);
	ft_putstr(scanner->userid);
	while (i > 0)
	{
		ft_putchar(' ');
		i--;
	}
	ft_putstr("  ");
}

void	ft_groupidprinter(t_file *scanner, size_t *padding)
{
	int		i;

	i = padding[3] - ft_strlen(scanner->groupid);
	ft_putstr(scanner->groupid);
	while (i > 0)
	{
		ft_putchar(' ');
		i--;
	}
	ft_putchar(' ');
}

void	ft_sizeprinter(t_file *scanner, size_t *padding)
{
	int		i;

	i = padding[1] - ft_intlen(scanner->size);
	while (i > 0)
	{
		ft_putchar(' ');
		i--;
	}
	ft_putnbr(scanner->size);
	ft_putchar(' ');
}

void	ft_dayprinter(t_file *scanner)
{
	if (ft_strlen(scanner->day) < 2)
	{
		ft_putchar(' ');
	}
	ft_putstr(scanner->day);
	ft_putchar(' ');
}
