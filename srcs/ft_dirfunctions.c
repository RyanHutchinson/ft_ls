/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dirfunctions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhutchin <rhutchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 13:51:45 by rhutchin          #+#    #+#             */
/*   Updated: 2019/07/10 10:29:59 by rhutchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_ls.h"

t_dirs	*ft_newdirs(char *path)
{
	t_dirs	*new;

	new = malloc(sizeof(t_dirs));
	new->dirname = ft_strdup(path);
	new->next = NULL;
	return (new);
}

t_dirs	*ft_adddir(char *path, t_dirs *dirs)
{
	t_dirs	*scanner;
	t_dirs	*tmp;

	if (dirs == NULL)
		dirs = ft_newdirs(path);
	else
	{
		scanner = dirs;
		while (scanner != NULL)
		{
			tmp = scanner;
			scanner = scanner->next;
		}
		tmp->next = ft_newdirs(path);
	}
	return (dirs);
}

void	ft_dirsdel(t_dirs *dirs)
{
	t_dirs	*scanner;
	t_dirs	*tmp;

	scanner = dirs;
	while (scanner != NULL)
	{
		tmp = dirs->next;
		ft_strdel(&scanner->dirname);
		dirs->next = NULL;
		scanner = tmp;
	}
}
