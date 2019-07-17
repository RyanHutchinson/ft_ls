/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhutchin <rhutchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 10:17:41 by rhutchin          #+#    #+#             */
/*   Updated: 2019/07/17 13:13:51 by rhutchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static char	ft_filetype(int mode)
{
	mode = (mode & S_IFMT);
	if (S_ISREG(mode))
		return ('-');
	else if (S_ISDIR(mode))
		return ('d');
	else if (S_ISLNK(mode))
		return ('l');
	else if (S_ISBLK(mode))
		return ('b');
	else if (S_ISCHR(mode))
		return ('c');
	else if (S_ISSOCK(mode))
		return ('s');
	else if (S_ISFIFO(mode))
		return ('p');
	else
		return ('-');
}

char		*ft_convertgid(struct stat stats)
{
	struct group	*grp;

	grp = getgrgid(stats.st_gid);
	if (grp != NULL)
		return (ft_strdup(grp->gr_name));
	else
		return (ft_itoa(stats.st_gid));
}

char		*ft_convertuid(struct stat stats)
{
	struct passwd	*user;

	user = getpwuid(stats.st_uid);
	if (user != NULL)
		return (ft_strdup(user->pw_name));
	else
		return (ft_itoa(stats.st_uid));
}

void		ft_converttime(t_file *node)
{
	char	*str;
	char	**arr;

	str = ctime(&node->rawtime);
	arr = ft_strsplit(str, ' ');
	node->month = ft_strdup(arr[1]);
	node->day = ft_strdup(arr[2]);
	node->time = ft_strsub(arr[3], 0, 5);
	node->year = ft_strdup(arr[4]);
	ft_strdel(&arr[0]);
	ft_strdel(&arr[1]);
	ft_strdel(&arr[2]);
	ft_strdel(&arr[3]);
	ft_strdel(&arr[4]);
	ft_strdel(&arr[5]);
	free(arr);
}

char		*ft_convertatt(struct stat stats)
{
	char		attr[11];

	attr[0] = ft_filetype(stats.st_mode);
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
