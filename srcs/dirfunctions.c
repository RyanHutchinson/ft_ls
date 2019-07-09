/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dirfunctions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhutchin <rhutchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 13:51:45 by rhutchin          #+#    #+#             */
/*   Updated: 2019/07/09 14:34:25 by rhutchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_ls.h"

t_dirs	*ft_newdirs(char *path)
{
	t_dirs	*new;

	new = malloc(sizeof(t_dirs));
	new->dirname = ft_strdup(path);
	new->next = NULL;
	return(new);
}

void	ft_adddir(char *path, t_dirs *dirs)
{
	if (dirs == NULL)
		dirs = ft_newdirs(path);
	else
	{
		t_dirs	*new;
		t_dirs	*scanner;

		scanner = dirs;
		while(scanner->next != NULL)
			scanner = scanner->next;
		new = malloc(sizeof(t_dirs));
		new->dirname = ft_strdup(path);
		new->next = NULL;
		scanner->next = new;
	}
}

void	ft_dirsdel(t_dirs *dirs)
{
	t_dirs	*scanner;

	scanner = dirs;
	while(scanner != NULL)
	{
		t_dirs	*tmp;

		tmp = dirs->next;
		ft_strdel(&scanner->dirname);
		dirs->next = NULL;
		scanner = tmp;
	}
}