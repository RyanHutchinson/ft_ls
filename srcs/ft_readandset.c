/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readandset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhutchin <rhutchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 14:23:13 by rhutchin          #+#    #+#             */
/*   Updated: 2019/07/15 10:39:07 by rhutchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_ls.h"

static char		*ft_fullpath(char *path, struct dirent *de)
{
	char			*tmppath;
	char			*fullpath;

	tmppath = ft_strjoin(path, "/");
	fullpath = ft_strjoin(tmppath, de->d_name);
	return (fullpath);
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
		printf("The bad has happened -_- you are nowhere\n");
	while ((de = readdir(dr)) != NULL)
	{
		fullpath = ft_fullpath(path, de);
		lstat(fullpath, &stats);
		if (de->d_name[0] == '.' && !(flags & FLAG_A))
		{
			continue;
		}
		else
		{
			*head = ft_addnode(*head, de->d_name, stats);
			if (strlen(de->d_name) > *minwidth)
				*minwidth = strlen(de->d_name);
		}
	}
	closedir(dr);
}
