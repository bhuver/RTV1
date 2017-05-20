/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhuver <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 17:24:42 by bhuver            #+#    #+#             */
/*   Updated: 2016/11/18 15:51:45 by bhuver           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

void			default_obj(t_obj *new)
{
	new->pos.x = 0;
	new->pos.y = 0;
	new->pos.z = 0;
	new->dir.x = 0;
	new->dir.y = 0;
	new->dir.z = 0;
	new->norm.x = 0;
	new->norm.y = 0;
	new->norm.z = 0;
	new->type = 0;
	new->rayon = 1;
	new->alpha = 0;
	new->mat.col = color_new(255, 255, 255);
	new->next = NULL;
}

t_obj			*push_obj(t_env *e)
{
	t_obj		*new;
	t_obj		*c;

	new = malloc(sizeof(t_obj));
	default_obj(new);
	new->next = NULL;
	c = e->objs;
	if (c)
		while (c->next)
			c = c->next;
	if (!c)
		e->objs = new;
	else
		c->next = new;
	return (new);
}
