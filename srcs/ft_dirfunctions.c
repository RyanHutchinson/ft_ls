/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dirfunctions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhutchin <rhutchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 13:51:45 by rhutchin          #+#    #+#             */
/*   Updated: 2019/07/17 12:31:25 by rhutchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

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

void	ft_dirsdel(t_dirs **dirs)
{
	t_dirs	*scanner;
	t_dirs	*next;

	scanner = *dirs;
	while (scanner != NULL)
	{
		next = scanner->next;
		ft_strdel(&scanner->dirname);
		free(scanner);
		scanner = next;
	}
}
