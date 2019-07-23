/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhutchin <rhutchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 10:59:48 by rhutchin          #+#    #+#             */
/*   Updated: 2019/07/23 09:35:37 by rhutchin         ###   ########.fr       */
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
	if (flags & FLAG_T)
		*head = ft_sortedmerge_t(fh, bh, flags);
	 else
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
