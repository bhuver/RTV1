/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersects.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhuver <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 17:43:46 by bhuver            #+#    #+#             */
/*   Updated: 2016/11/18 18:00:43 by bhuver           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

float				int_cone(t_obj *obj, t_ray ray)
{
	float			solut;
	float			f[6];
	t_vect			tmp;

	tmp = vec_sub(ray.orig, obj->pos);
	f[0] = vec_dot(ray.dir, ray.dir) - ((1.0 + SQ(obj->alpha)) *
									SQ(vec_dot(ray.dir, obj->dir)));
	f[1] = 2.0 * (vec_dot(ray.dir, tmp) - ((1.0 + SQ(obj->alpha))
										* vec_dot(ray.dir, obj->dir)
										* vec_dot(tmp, obj->dir)));
	f[2] = vec_dot(tmp, tmp) - ((1.0 + SQ(obj->alpha)) *
							SQ(vec_dot(tmp, obj->dir)));
	f[3] = SQ(f[1]) - 4.0 * f[0] * f[2];
	if (f[3] >= 0.0)
	{
		f[3] = sqrt(f[3]);
		f[4] = (-f[1] + f[3]) / (2.0 * f[0]);
		f[5] = (-f[1] - f[3]) / (2.0 * f[0]);
		solut = f[4] < f[5] ? f[4] : f[5];
		if (solut > EPSILON)
			return (solut);
	}
	return (-1);
}

float				int_cylindre(t_obj *obj, t_ray ray)
{
	float			f[4];
	float			t[2];
	float			tv[2];
	t_vect			x;

	obj->dir = vec_normalize(obj->dir);
	x = vec_sub(ray.orig, obj->pos);
	f[0] = vec_dot(ray.dir, ray.dir) - SQ(vec_dot(ray.dir, obj->dir));
	f[1] = 2 * (vec_dot(ray.dir, x) - vec_dot(ray.dir, obj->dir) *
			vec_dot(x, obj->dir));
	f[2] = vec_dot(x, x) - SQ(vec_dot(x, obj->dir)) - SQ(obj->rayon);
	f[3] = (f[1] * f[1]) - 4.0 * f[0] * f[2];
	if (f[3] < 0)
		return (-1.0);
	if (f[3] == 0.0)
		return (-f[1] / 2.0 * f[0]);
	t[0] = (-f[1] - sqrt(f[3])) / (2.0 * f[0]);
	t[1] = (-f[1] + sqrt(f[3])) / (2.0 * f[0]);
	tv[0] = t[0] < t[1] ? t[0] : t[1];
	tv[1] = t[0] > t[1] ? t[0] : t[1];
	if (tv[0] < 0 && tv[1] < 0)
		return (-1);
	else if (tv[0] < 0)
		return (tv[1]);
	return (tv[0]);
}

float				int_sphere(t_obj *obj, t_ray ray)
{
	float			solut;
	float			f[6];

	f[0] = SQ(ray.dir.x) + SQ(ray.dir.y) + SQ(ray.dir.z);
	f[1] = 2.0 * (ray.dir.x * (ray.orig.x - obj->pos.x) + ray.dir.y *
			(ray.orig.y - obj->pos.y) + ray.dir.z
				* (ray.orig.z - obj->pos.z));
	f[2] = (SQ(ray.orig.x - obj->pos.x) + SQ(ray.orig.y - obj->pos.y) +
		SQ(ray.orig.z - obj->pos.z)) - SQ(obj->rayon);
	f[3] = (f[1] * f[1]) - 4.0 * f[0] * f[2];
	if (f[3] >= 0)
	{
		f[3] = sqrt(f[3]);
		f[4] = (-f[1] + f[3]) / (2.0 * f[0]);
		f[5] = (-f[1] - f[3]) / (2.0 * f[0]);
		solut = f[4] > f[5] ? f[5] : f[4];
		if (solut > EPSILON)
			return (solut);
	}
	return (-1);
}

float				int_plan(t_obj *obj, t_ray ray)
{
	float			solut;

	solut = -vec_dot(vec_sub(ray.orig, obj->pos), obj->norm) /
		vec_dot(obj->norm, ray.dir);
	if (solut > EPSILON)
		return (solut);
	return (-1);
}
