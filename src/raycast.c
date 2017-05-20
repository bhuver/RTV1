/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-la-s <vde-la-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 20:51:51 by bhuver            #+#    #+#             */
/*   Updated: 2016/11/18 15:54:22 by bhuver           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

void			int_objs(t_env *e)
{
	float		tmp;
	t_obj		*obj;

	obj = e->objs;
	e->ray.solut = -1;
	tmp = -1;
	while (obj)
	{
		obj->type == SPHERE ? tmp = int_sphere(obj, e->ray) : 0;
		obj->type == PLAN ? tmp = int_plan(obj, e->ray) : 0;
		obj->type == CYLINDRE ? tmp = int_cylindre(obj, e->ray) : 0;
		obj->type == CONE ? tmp = int_cone(obj, e->ray) : 0;
		if ((tmp < e->ray.solut || e->ray.solut == -1) && tmp != -1)
		{
			e->ray.obj_hit = obj;
			e->ray.solut = tmp;
		}
		obj = obj->next;
	}
}

t_color			render_ray(t_env *e)
{
	t_color		color;

	if (e->ray.solut != -1 && e->ray.obj_hit)
		color = render_light(e);
	else
		color = color_new(0, 0, 0);
	return (color);
}

t_color			init_ray(t_env *e, int x, int y)
{
	t_vect		view_point;

	view_point = vec_sub(vec_add(e->cam.up_left,
								vec_cmul(e->cam.right, e->cam.x_ind * x)),
						vec_cmul(e->cam.up, e->cam.y_ind * y));
	e->ray.dir = vec_normalize(vec_sub(view_point, e->cam.pos));
	int_objs(e);
	return (render_ray(e));
}

void			raycast(t_env *e)
{
	int			x;
	int			y;

	y = -1;
	x = -1;
	e->ray.orig = e->cam.pos;
	while (++y < HEIGHT && (x = -1) < 0)
		while (++x < WIDTH)
			put_pixel(e, init_ray(e, x, y), x, y);
}
