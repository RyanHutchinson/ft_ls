/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readandset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhutchin <rhutchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 14:23:13 by rhutchin          #+#    #+#             */
/*   Updated: 2019/07/11 08:53:16 by rhutchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_ls.h"

void	ft_readandbuild(int flags, char *path, t_file **head, size_t *minwidth)
{
	DIR				*dr;
	struct dirent	*de;
	struct stat		stats;

	dr = opendir(path);
	if (dr == NULL)
		printf("The bad has happened -_- you are nowhere\n");
	while ((de = readdir(dr)) != NULL)
	{
		lstat(ft_strjoin(ft_strjoin(path, "/"), de->d_name), &stats);
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
