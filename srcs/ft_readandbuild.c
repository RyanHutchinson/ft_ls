/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readandbuild.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhutchin <rhutchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 14:23:13 by rhutchin          #+#    #+#             */
/*   Updated: 2019/07/17 10:56:53 by rhutchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void		ft_fullpath(char *path, char *path2, char **fullpath)
{
	char			*tmppath;

	tmppath = ft_strjoin(path, "/");
	*fullpath = ft_strjoin(tmppath, path2);
	ft_strdel(&tmppath);
}

void			ft_readandbuild(int flags, char *path, t_file **head)
{
	DIR				*dr;
	struct dirent	*de;
	struct stat		stats;
	char			*fullpath;

	dr = opendir(path);
	if (errno == 20)
	{
		lstat(path, &stats);
		*head = ft_addnode(*head, path, stats);
	}
	else
	{
		while ((de = readdir(dr)) != NULL)
		{
			ft_fullpath(path, de->d_name, &fullpath);
			lstat(fullpath, &stats);
			ft_strdel(&fullpath);
			if (de->d_name[0] == '.' && !(flags & FLAG_A))
			{
				continue;
			}
			else
			{
				*head = ft_addnode(*head, de->d_name, stats);
			}
		}
		closedir(dr);
	}
}
