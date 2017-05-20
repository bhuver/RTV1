/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhuver <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 15:48:53 by bhuver            #+#    #+#             */
/*   Updated: 2016/11/18 16:54:35 by bhuver           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

void			norm_cone(t_ray *ray)
{
	float		t;
	float		beta;
	t_vect		dir;

	dir = (ray->obj_hit)->dir;
	beta = vec_dot(vec_normalize(vec_sub(ray->hit_point,
										(ray->obj_hit)->pos)), dir);
	if ((acos(beta) * 180.0 / M_PI) > 90.0)
	{
		dir = vec_cmul(dir, -1);
		beta = vec_dot(vec_normalize(vec_sub(ray->hit_point,
											(ray->obj_hit)->pos)), dir);
	}
	t = (dist_p((ray->obj_hit)->pos, ray->hit_point) * sin(beta))
		/ sin(1.5708 + beta);
	dir = vec_cmul(dir, t);
	dir = vec_add((ray->obj_hit)->pos, dir);
	ray->norm = vec_normalize(vec_sub(ray->hit_point, dir));
}

void			norm_cylindre(t_ray *ray)
{
	float		t;
	t_vect		dir;
	t_vect		pos;

	dir = (ray->obj_hit)->dir;
	pos = (ray->obj_hit)->pos;
	t = (-dir.x * pos.x - dir.y * pos.y - dir.z * pos.z + ray->hit_point.x *
		dir.x + ray->hit_point.y * dir.y + ray->hit_point.z * dir.z) /
		(SQ(dir.x) + SQ(dir.y) + SQ(dir.z));
	ray->norm = vec_new(ray->hit_point.x - (pos.x + dir.x * t),
						ray->hit_point.y - (pos.y + dir.y * t),
						ray->hit_point.z - (pos.z + dir.z * t));
	ray->norm = vec_normalize(ray->norm);
}

t_color			diffuse_lgt(t_env *e)
{
	t_color		c;
	float		cos;
	t_vect		light;

	c = color_new(0, 0, 0);
	light = vec_normalize(vec_sub(e->lgt.pos, e->ray.hit_point));
	cos = vec_dot(light, e->ray.norm);
	if (cos < 0 && (e->ray.obj_hit)->type == PLAN)
		cos *= -1;
	if (cos > 0)
		c = color_add(color_add(c, color_mul(e->lgt.col,
											e->lgt.intensity * cos)),
					color_mul((e->ray.obj_hit)->mat.col,
								e->lgt.intensity * cos));
	return (c);
}

int				is_shadowed(t_env *e)
{
	t_ray		save_ray;
	t_vect		tmp;

	save_ray = e->ray;
	e->ray.orig = e->lgt.pos;
	e->ray.dir = vec_normalize(vec_sub(e->ray.hit_point, e->lgt.pos));
	int_objs(e);
	tmp = vec_add(e->ray.orig, vec_cmul(e->ray.dir, e->ray.solut));
	e->ray = save_ray;
	if (dist_p(tmp, e->lgt.pos) < dist_p(e->ray.hit_point,
										e->lgt.pos) - EPSILON)
		return (0);
	return (1);
}

t_color			render_light(t_env *e)
{
	t_color		c;

	c = color_new(0, 0, 0);
	if (e->ray.solut != -1 && e->ray.obj_hit)
	{
		e->ray.hit_point = vec_add(e->ray.orig,
								vec_cmul(e->ray.dir, e->ray.solut));
		if ((e->ray.obj_hit)->type == SPHERE)
			e->ray.norm = vec_normalize(vec_sub(e->ray.hit_point,
												(e->ray.obj_hit)->pos));
		if ((e->ray.obj_hit)->type == PLAN)
			e->ray.norm = (e->ray.obj_hit)->norm;
		if ((e->ray.obj_hit)->type == CYLINDRE)
			norm_cylindre(&e->ray);
		if ((e->ray.obj_hit)->type == CONE)
			norm_cone(&e->ray);
		e->ray.norm = vec_normalize(e->ray.norm);
		if (is_shadowed(e))
			c = color_stack(c, diffuse_lgt(e));
		c = color_add(c, color_mul((e->ray.obj_hit)->mat.col, 0.2));
	}
	return (c);
}
