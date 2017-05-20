/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhuver <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/15 13:23:31 by bhuver            #+#    #+#             */
/*   Updated: 2016/05/17 19:40:03 by bhuver           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "raytracer.h"

int			get_next_line(int const fd, char **line)
{
	static t_gnl_mem	*mem;
	t_gnl_mem			*track;
	int					rv;

	if (fd < 0 || !line)
		return (-1);
	if (!mem)
		mem = ft_list_fillnext(mem, fd);
	track = mem;
	while (track->next && track->fd != fd)
		track = track->next;
	if (track->fd != fd)
	{
		track->next = ft_list_fillnext(track, fd);
		track = track->next;
	}
	if (!(rv = read_line(track, line)))
		free_mem(&mem, fd);
	return (rv);
}

int			read_line(t_gnl_mem *track, char **line)
{
	char	buffer[BUFF_SIZE + 1];
	char	*tmp;
	int		rbv;
	size_t	len;
	size_t	i;

	if (ft_memset(buffer, '\0', BUFF_SIZE + 1) && prepare_line(track, line))
		return (1);
	while ((rbv = read(track->fd, buffer, BUFF_SIZE)) > 0)
	{
		ft_strappend(line, buffer);
		len = ft_strlen(*line);
		i = 0;
		while (i < len)
			if ((*line)[i++] == '\n')
			{
				tmp = *line;
				*line = ft_strsub(*line, 0, i - 1);
				ft_strappend(&track->bnl, tmp + i);
				free(tmp);
				return (rbv > 1 ? 1 : rbv);
			}
		ft_memset(buffer, '\0', BUFF_SIZE + 1);
	}
	return (rbv > 1 || (*line && (ft_strlen(*line)) && !rbv) ? 1 : rbv);
}

t_gnl_mem	*ft_list_fillnext(t_gnl_mem *mem, int fd)
{
	if (!mem)
	{
		mem = (t_gnl_mem*)(malloc(sizeof(t_gnl_mem)));
		mem->fd = fd;
		mem->bnl = ft_strdup("");
		mem->next = NULL;
		return (mem);
	}
	mem->next = (t_gnl_mem*)(malloc(sizeof(t_gnl_mem)));
	mem = mem->next;
	mem->fd = fd;
	mem->bnl = ft_strdup("");
	mem->next = NULL;
	return (mem);
}

int			prepare_line(t_gnl_mem *track, char **line)
{
	int		i;
	int		len;
	int		ret;
	char	*new_bnl;

	len = 0;
	while (track->bnl[len] != '\n' && track->bnl[len] != '\0')
		len++;
	ret = (track->bnl[len] == '\n') ? 1 : 0;
	*line = ft_strnew(len + 1);
	i = -1;
	while (++i < len)
		(*line)[i] = track->bnl[i];
	if (track->bnl[len] == '\n')
		new_bnl = ft_strdup(track->bnl + len + 1);
	else
		new_bnl = ft_strdup("");
	free(track->bnl);
	track->bnl = new_bnl;
	return (ret);
}

void		free_mem(t_gnl_mem **mem, int fd)
{
	t_gnl_mem *track;

	if (*mem && (*mem)->fd == fd)
	{
		track = (*mem)->next;
		free((*mem)->bnl);
		free(*mem);
		*mem = track;
		return ;
	}
	while (*mem && (*mem)->fd != fd)
	{
		track = *mem;
		*mem = (*mem)->next;
	}
	if (*mem)
	{
		free((*mem)->bnl);
		track->next = (*mem)->next;
		free(*mem);
	}
}
