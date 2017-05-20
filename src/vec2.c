/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhuver <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 16:02:03 by bhuver            #+#    #+#             */
/*   Updated: 2016/11/14 16:03:05 by bhuver           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

t_vect			vec_normalize(t_vect a)
{
	float		magn;

	magn = sqrt((a.x * a.x) + (a.y * a.y) + (a.z * a.z));
	a.x /= magn;
	a.y /= magn;
	a.z /= magn;
	return (a);
}

float			vec_dot(t_vect a, t_vect b)
{
	return ((a.x * b.x) + (a.y * b.y) + (a.z * b.z));
}

t_vect			cross_pr(t_vect u, t_vect v)
{
	t_vect		w;

	w.x = (u.y * v.z) - (u.z * v.y);
	w.y = (u.z * v.x) - (u.x * v.z);
	w.z = (u.x * v.y) - (u.y * v.x);
	return (w);
}

float			dist_p(t_vect u, t_vect v)
{
	float		d;

	d = sqrt(SQ(u.x - v.x) + SQ(u.y - v.y) + SQ(u.z - v.z));
	return (d);
}
