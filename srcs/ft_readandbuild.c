/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readandbuild.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhutchin <rhutchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 14:23:13 by rhutchin          #+#    #+#             */
/*   Updated: 2019/07/16 11:44:41 by rhutchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void		ft_fullpath(char *path, struct dirent *de, char **fullpath)
{
	char			*tmppath;

	tmppath = ft_strjoin(path, "/");
	*fullpath = ft_strjoin(tmppath, de->d_name);
	ft_strdel(&tmppath);
}

void			ft_readandbuild(int flags, char *path, t_file **head,\
													size_t *minwidth)
{
	DIR				*dr;
	struct dirent	*de;
	struct stat		stats;
	char			*fullpath;

	dr = opendir(path);
	if (dr == NULL)
	{
		printf("the path: %s is not openable?", path);//---------------------- Printf
		return;
	}
	while ((de = readdir(dr)) != NULL)
	{
		ft_fullpath(path, de, &fullpath);
		lstat(fullpath, &stats);
		ft_strdel(&fullpath);
		if (de->d_name[0] == '.' && !(flags & FLAG_A))
		{
			continue;
		}
		else
		{
			*head = ft_addnode(*head, de->d_name, stats);
			if (ft_strlen(de->d_name) > *minwidth)
				*minwidth = ft_strlen(de->d_name);
		}
	}
	closedir(dr);
}
