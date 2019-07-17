/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printerformatting.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhutchin <rhutchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 15:16:11 by rhutchin          #+#    #+#             */
/*   Updated: 2019/07/17 16:00:26 by rhutchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	ft_linksprinter(t_file *scanner, t_file **head)
{
	t_file	*scanner2;
	int		i;

	scanner2 = *head;
	i = 0;
	while (scanner2 != NULL)
	{
		if (i < ft_intlen(scanner2->links))
			i = ft_intlen(scanner2->links);
		scanner2 = scanner2->next;
	}
	i = i - ft_intlen(scanner->links);
	while (i > 0)
	{
		ft_putchar(' ');
		i--;
	}
	ft_putnbr(scanner->links);
	ft_putchar(' ');
}

void	ft_sizeprinter(t_file *scanner, t_file **head)
{
	t_file	*scanner2;
	int		i;

	scanner2 = *head;
	i = 0;
	while (scanner2 != NULL)
	{
		if (i < ft_intlen(scanner2->size))
			i = ft_intlen(scanner2->size);
		scanner2 = scanner2->next;
	}
	i = i - ft_intlen(scanner->size);
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
	if (ft_atoi(scanner->day) <= 9)
		ft_putchar(' ');
	ft_putstr(scanner->day);
	ft_putchar(' ');
}
