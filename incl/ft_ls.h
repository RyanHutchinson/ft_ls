/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhutchin <rhutchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 10:44:13 by rhutchin          #+#    #+#             */
/*   Updated: 2019/07/08 16:08:56 by rhutchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include "../libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>     //----------------------------------------------------- Makes the DIR opening, closing and reading magic happen.
#include <sys/stat.h>   //----------------------------------------------------- Makes checking for file stats happen...
#include <sys/types.h>  //----------------------------------------------------- Makes various types available for use...
#include <grp.h>		//----------------------------------------------------- Makes conversions of user/group ID's from int to char*
#include <pwd.h>		//----------------------------------------------------- As above
#include <time.h>		//----------------------------------------------------- Makes conversions of int time to readable human time through ctime(s_flags.time)
#include <stdio.h>      //----------------------------------------------------- Delete me mc cheaty

typedef	struct		s_file
{
	char			*attributes;
	char			*file_name;
	unsigned int	links;
	char			*userID;
	char			*groupID;
	int				size;
	time_t			rawtime;
	char			*day;
	char			*month;
	char			*year;
	char			*time;
	struct s_file	*next;
	struct s_file	*previous;
}                   t_file;

typedef	struct		s_flags
{
	unsigned char   flags;
}                   t_flags;

void		    ft_ls(int ac, char **av);

void 		    ft_listbuilder(t_flags flags, t_file *head, char *open);
unsigned char	ft_flagchecker(int ac, char **av);
void		    ft_listprinter(t_file *head, size_t minwidth, t_flags flags);

t_file		    *ft_newnode();
void		    ft_addnode(t_file *node, char *file_name, struct stat stats);
void		    ft_sortlist(t_file *head);
void            ft_revlist(t_file *head);
void	   		ft_sortlisttime(t_file *head);

char			*ft_convertUID(struct stat stats);
char			*ft_convertGID(struct stat stats);
void			ft_convertTime(t_file *node);
char			*ft_convertAtt(struct stat stats);

#endif
