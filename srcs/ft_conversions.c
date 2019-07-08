/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhutchin <rhutchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 10:17:41 by rhutchin          #+#    #+#             */
/*   Updated: 2019/07/08 12:08:31 by rhutchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_ls.h"

char	*ft_convertUID(struct stat stats)
{
	struct group	*grp;

	grp = getgrgid(stats.st_gid);
	return (ft_strdup(grp->gr_name));
}

char	*ft_convertGID(struct stat stats)
{
	struct passwd	*user;

	user  = getpwuid(stats.st_uid);
	return (ft_strdup(user->pw_name));
}

void	ft_convertTime(t_file *node)
{
	char	*str;
	char	**arr;

	str = ctime(&node->rawtime);
//	node->time = strdup(str);
	arr = ft_strsplit(str, ' ');
//	ft_strdel(&str);
//	ft_strdel(&arr[0]);
	node->month = ft_strdup(arr[1]);
	node->day = ft_strdup(arr[2]);
	node->time = ft_strsub(arr[3], 0, 5);
	node->year = ft_strdup(arr[4]);
//	free(arr);
}

char	*ft_convertAtt(struct stat stats)
{
	char		attr[11];

	attr[0] = ((S_ISDIR(stats.st_mode)) ? 'd' : '-');
	attr[1] = ((stats.st_mode & S_IRUSR) ? 'r' : '-');
	attr[2] = ((stats.st_mode & S_IWUSR) ? 'w' : '-');
	attr[3] = ((stats.st_mode & S_IXUSR) ? 'x' : '-');
	attr[4] = ((stats.st_mode & S_IRGRP) ? 'r' : '-');
	attr[5] = ((stats.st_mode & S_IWGRP) ? 'w' : '-');
	attr[6] = ((stats.st_mode & S_IXGRP) ? 'x' : '-');
	attr[7] = ((stats.st_mode & S_IROTH) ? 'r' : '-');
	attr[8] = ((stats.st_mode & S_IWOTH) ? 'w' : '-');
	attr[9] = ((stats.st_mode & S_IXOTH) ? 'x' : '-');
	attr[10] = '\0';

	return (ft_strdup(attr));
}