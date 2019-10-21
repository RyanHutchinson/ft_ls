/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_timesorters.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhutchin <rhutchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 09:34:43 by rhutchin          #+#    #+#             */
/*   Updated: 2019/07/23 09:56:08 by rhutchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void	ft_checknanohelper(int flags, t_file *fh, t_file *bh, \
t_file **result)
{
	if (!(flags & FLAG_R) && (ft_strcmp(fh->file_name, bh->file_name)) < 0)
	{
		*result = fh;
		(*result)->next = ft_sortedmerge_t(fh->next, bh, flags);
	}
	else if ((flags & FLAG_R) && (ft_strcmp(fh->file_name, bh->file_name)) > 0)
	{
		*result = fh;
		(*result)->next = ft_sortedmerge_t(fh->next, bh, flags);
	}
	else
	{
		*result = bh;
		(*result)->next = ft_sortedmerge_t(fh, bh->next, flags);
	}
}

t_file		*ft_sortedmerge_t(t_file *fh, t_file *bh, int flags)
{
	t_file *result;

	result = NULL;
	if (fh == NULL)
		return (bh);
	else if (bh == NULL)
		return (fh);
	if (!(flags & FLAG_R) && (fh->rawtime > bh->rawtime))
	{
		result = fh;
		result->next = ft_sortedmerge_t(fh->next, bh, flags);
	}
	else if ((flags & FLAG_R) && (fh->rawtime < bh->rawtime))
	{
		result = fh;
		result->next = ft_sortedmerge_t(fh->next, bh, flags);
	}
	else if (fh->rawtime == bh->rawtime)
		ft_checknano(flags, fh, bh, &result);
	else
	{
		result = bh;
		result->next = ft_sortedmerge_t(fh, bh->next, flags);
	}
	return (result);
}

void		ft_checknano(int flags, t_file *fh, t_file *bh,
t_file **result)
{
	if (!(FLAG_R & flags) && (fh->rawtimen > bh->rawtimen))
	{
		*result = fh;
		(*result)->next = ft_sortedmerge_t(fh->next, bh, flags);
	}
	else if ((FLAG_R & flags) && (fh->rawtimen < bh->rawtimen))
	{
		*result = fh;
		(*result)->next = ft_sortedmerge_t(fh->next, bh, flags);
	}
	else if (fh->rawtimen == bh->rawtimen)
	{
		ft_checknanohelper(flags, fh, bh, result);
	}
	else
	{
		*result = bh;
		(*result)->next = ft_sortedmerge_t(fh, bh->next, flags);
	}
}
