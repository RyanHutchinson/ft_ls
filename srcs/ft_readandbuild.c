/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readandbuild.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhutchin <rhutchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 14:23:13 by rhutchin          #+#    #+#             */
/*   Updated: 2019/07/23 14:30:13 by rhutchin         ###   ########.fr       */
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

static void		ft_reader(int flags, char *path, t_file **head, DIR *dr)
{
	struct dirent	*de;
	struct stat		stats;
	char			*fullpath;

	while ((de = readdir(dr)) != NULL)
	{
		ft_fullpath(path, de->d_name, &fullpath);
		lstat(fullpath, &stats);
		ft_strdel(&fullpath);
		if (de->d_name[0] == '.' && !(flags & FLAG_A))
			continue;
		else
			*head = ft_addnode(*head, de->d_name, stats);
	}
}

void			ft_readandbuild(int flags, char *path, t_file **head)
{
	DIR				*dr;
	struct stat		stats;

	dr = opendir(path);
	if (errno == 20)
	{
		lstat(path, &stats);
		*head = ft_addnode(*head, path, stats);
	}
	else if (errno == 13)
		ft_lserror(3, path);
	else if (errno == 2)
	{
		ft_lserror(2, path);
		errno = 0;
	}
	else
	{
		ft_reader(flags, path, head, dr);
		closedir(dr);
	}
}
