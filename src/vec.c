/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-la-s <vde-la-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 22:10:12 by bhuver            #+#    #+#             */
/*   Updated: 2016/11/14 16:01:05 by bhuver           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

t_vect			vec_new(float x, float y, float z)
{
	t_vect	new;

	new.x = x;
	new.y = y;
	new.z = z;
	return (new);
}

t_vect			vec_add(t_vect a, t_vect b)
{
	a.x += b.x;
	a.y += b.y;
	a.z += b.z;
	return (a);
}

t_vect			vec_sub(t_vect a, t_vect b)
{
	a.x -= b.x;
	a.y -= b.y;
	a.z -= b.z;
	return (a);
}

t_vect			vec_mul(t_vect a, t_vect b)
{
	a.x *= b.x;
	a.y *= b.y;
	a.z *= b.z;
	return (a);
}

t_vect			vec_cmul(t_vect a, float b)
{
	a.x *= b;
	a.y *= b;
	a.z *= b;
	return (a);
}
