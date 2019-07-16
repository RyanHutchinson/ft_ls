/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhutchin <rhutchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 10:59:48 by rhutchin          #+#    #+#             */
/*   Updated: 2019/07/16 09:28:51 by rhutchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void		ft_sortlist(t_file **head, int flags)
{
	t_file	*tmphead;
	t_file	*fh;
	t_file	*bh;

	tmphead = *head;
	if ((tmphead == NULL) || (tmphead->next == NULL))
		return ;
	frontbacksplit(tmphead, &fh, &bh);
	ft_sortlist(&fh, flags);
	ft_sortlist(&bh, flags);
	*head = ft_sortedmerge(fh, bh, flags);
}

void		frontbacksplit(t_file *tmphead, t_file **fh, t_file **bh)
{
	t_file *fast;
	t_file *slow;

	slow = tmphead;
	fast = tmphead->next;
	while (fast != NULL)
	{
		fast = fast->next;
		if (fast != NULL)
		{
			slow = slow->next;
			fast = fast->next;
		}
	}
	*fh = tmphead;
	*bh = slow->next;
	slow->next = NULL;
}

t_file		*ft_sortedmerge(t_file *fh, t_file *bh, int flags)
{
	t_file *result;

	result = NULL;
	if (fh == NULL)
		return (bh);
	else if (bh == NULL)
		return (fh);
	if (!(flags & FLAG_R) && (ft_strcmp(fh->file_name, bh->file_name)) < 0)
	{
		result = fh;
		result->next = ft_sortedmerge(fh->next, bh, flags);
	}
	else if ((flags & FLAG_R) && (ft_strcmp(fh->file_name, bh->file_name)) > 0)
	{
		result = fh;
		result->next = ft_sortedmerge(fh->next, bh, flags);
	}
	else
	{
		result = bh;
		result->next = ft_sortedmerge(fh, bh->next, flags);
	}
	return (result);
}
// static void	ft_timeswap(t_file **head)
// {
// 	t_file	*scan1;
// 	t_file	*scan2;
// 	t_file	*scanner;

// 	scanner = *head;
// 	while (scanner != NULL)
// 	{
// 		scan1 = scanner;
// 		scan2 = scan1->next;
// 		if (scan2 == NULL)
// 			break ;
// 		if ((ft_strcmp(scan1->time, scan2->time) == 0) && \
// 		ft_strcmp(scan1->file_name, scan2->file_name) < 0)
// 			ft_nodeswap(&scan1, &scan2, head, &scanner);
// 		else
// 			scanner = scanner->next;
// 	}
// }

// void		ft_sortlisttime(t_file **head)
// {
// 	t_file	*scan1;
// 	t_file	*scan2;
// 	t_file	*scanner;

// 	scanner = *head;
// 	while (scanner != NULL)
// 	{
// 		scan1 = scanner;
// 		scan2 = scan1->next;
// 		if (scan2 == NULL)
// 			break ;
// 		if ((scan1->rawtime - scan2->rawtime) < 0)
// 			ft_nodeswap(&scan1, &scan2, head, &scanner);
// 		else
// 			scanner = scanner->next;
// 	}
// 	ft_timeswap(head);
// }
