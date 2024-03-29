/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhutchin <rhutchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 10:44:13 by rhutchin          #+#    #+#             */
/*   Updated: 2019/07/24 07:55:03 by rhutchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <grp.h>
# include <pwd.h>
# include <time.h>
# include <errno.h>
# include <stdio.h>

# define BIT(X) (1 << X)

# define FLAG_L BIT(0)
# define FLAG_A BIT(1)
# define FLAG_RECURSE BIT(2)
# define FLAG_R BIT(3)
# define FLAG_T BIT(4)

typedef	struct		s_file
{
	char			*attributes;
	char			*file_name;
	unsigned int	links;
	long			blocks;
	char			*userid;
	char			*groupid;
	size_t			size;
	time_t			rawtime;
	time_t			rawtimen;
	char			*day;
	char			*month;
	char			*year;
	char			*time;
	struct s_file	*next;
	struct s_file	*previous;
}					t_file;

typedef	struct		s_dirs
{
	char			*dirname;
	struct s_dirs	*next;
}					t_dirs;

void				ft_readandbuild(int flags, char *path, t_file **head);
void				ft_lsengine(int flags, char *path);
t_dirs				*ft_argparser(int ac, char **av, t_dirs **dirs, int *flags);
void				ft_flagsetter(int *flags, char *str);

void				ft_listprinter(t_file *head, int flags, char *path);
void				ft_printiterator(t_file **scanner, int flags, char *path, \
															size_t *padding);
void				ft_longprinter(t_file *scanner, char *path,\
															size_t *padding);
void				ft_linksprinter(t_file *scanner, size_t *padding);
void				ft_useridprinter(t_file *scanner, size_t *padding);
void				ft_groupidprinter(t_file *scanner, size_t *padding);
void				ft_sizeprinter(t_file *scanner, size_t *padding);
void				ft_dayprinter(t_file *scanner);

t_dirs				*ft_adddir(char *path, t_dirs *dirs);
t_dirs				*ft_newdirs(char *path);
void				ft_dirsdel(t_dirs **dirs);

t_file				*ft_newnode();
t_file				*ft_addnode(t_file *node, char *file_name,\
											struct stat stats);
void				ft_nodeswap(t_file **scan1, t_file **scan2, t_file **head,\
															t_file **scanner);
void				ft_sortlist(t_file **head, int flags);
void				frontbacksplit(t_file *tmphead, t_file **fh, t_file **bh);
t_file				*ft_sortedmerge(t_file *fh, t_file *bh, int flags);
t_file				*ft_sortedmerge_t(t_file *fh, t_file *bh, int c);
void				ft_checknano(int c, t_file *fh, t_file *bh, \
															t_file **result);
void				ft_dellist(t_file **head);

char				*ft_convertuid(struct stat stats);
char				*ft_convertgid(struct stat stats);
void				ft_converttime(t_file *node);
char				*ft_convertatt(struct stat stats);

void				ft_lserror(int error, char *str);

#endif
