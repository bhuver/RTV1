/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhuver <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 21:26:32 by bhuver            #+#    #+#             */
/*   Updated: 2016/11/21 09:32:31 by bhuver           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

void			get_objects(t_env *e, char **file, int i)
{
	t_obj		*new;

	new = push_obj(e);
	while (file[i] && ft_strcmp(file[i], "") != 0)
	{
		ft_isin("sphere:", file[i]) ? new->type = SPHERE : 0;
		ft_isin("plan:", file[i]) ? new->type = PLAN : 0;
		ft_isin("cone:", file[i]) ? new->type = CONE : 0;
		ft_isin("cylindre:", file[i]) ? new->type = CYLINDRE : 0;
		if (ft_isin("pos:", file[i]))
			new->pos = read_vector(file[i]);
		if (ft_isin("dir:", file[i]))
			new->dir = read_vector(file[i]);
		if (ft_isin("nor:", file[i]))
			new->norm = read_vector(file[i]);
		if (ft_isin("alpha:", file[i]))
			new->alpha = get_fafter(':', file[i]) * M_PI / 180;
		if (ft_isin("rad:", file[i]))
			new->rayon = get_iafter(':', file[i]);
		if (ft_isin("col:", file[i]))
			new->mat.col = read_color(file[i]);
		i++;
	}
	(new->alpha > 15707) ? new->alpha = 1.5707 : 0;
}

void			get_light(t_env *e, char **file, int i)
{
	while (file[i] && ft_strcmp(file[i], "") != 0)
	{
		if (ft_isin("pos:", file[i]))
			e->lgt.pos = read_vector(file[i]);
		if (ft_isin("int:", file[i]))
			e->lgt.intensity = get_fafter(':', file[i]);
		if (ft_isin("col:", file[i]))
			e->lgt.col = read_color(file[i]);
		i++;
	}
}

void			get_cam(t_env *e, char **file, int i)
{
	while (file[i] && ft_strcmp(file[i], "") != 0)
	{
		if (ft_isin("pos:", file[i]))
			e->cam.pos = read_vector(file[i]);
		if (ft_isin("dir:", file[i]))
			e->cam.dir = read_vector(file[i]);
		i++;
	}
}

void			parse_file(t_env *e, char **file)
{
	int			i;

	i = 0;
	while (file[i])
	{
		if (ft_isin("cam:", file[i]))
			get_cam(e, file, i);
		if (ft_isin("light:", file[i]))
			get_light(e, file, i);
		if (ft_isin("sphere:", file[i]) || ft_isin("plan:", file[i]) ||
			ft_isin("cone:", file[i]) || ft_isin("cylindre:", file[i]))
			get_objects(e, file, i);
		i++;
	}
}

void			read_file(t_env *e, char *filename)
{
	int			fdn[2];
	char		*line;
	char		*file[999];

	fdn[1] = -1;
	if ((fdn[0] = open(filename, O_RDONLY)))
	{
		while ((get_next_line(fdn[0], &line) > 0) && ++fdn[1] < 998)
		{
			file[fdn[1]] = ft_strdup(line);
			free(line);
		}
		line ? free(line) : 0;
		file[fdn[1] + 1] = NULL;
		parse_file(e, file);
		fdn[1] = 0;
		while (file[fdn[1]])
			free(file[fdn[1]++]);
		close(fdn[0]);
	}
	else
	{
		ft_putendl_fd("Error opening file", 2);
		exit(-1);
	}
}
