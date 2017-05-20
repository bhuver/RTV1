/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhuver <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/15 13:23:50 by bhuver            #+#    #+#             */
/*   Updated: 2016/11/14 16:12:16 by bhuver           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# define BUFF_SIZE 96

typedef struct			s_gnl_mem
{
	int					fd;
	char				*bnl;
	struct s_gnl_mem	*next;
}						t_gnl_mem;

int						get_next_line(int const fd, char **line);
int						read_line(t_gnl_mem *t, char **line);
t_gnl_mem				*ft_list_fillnext(t_gnl_mem *mem, int fd);
int						prepare_line(t_gnl_mem *track, char **line);
void					free_mem(t_gnl_mem **mem, int fd);

#endif
