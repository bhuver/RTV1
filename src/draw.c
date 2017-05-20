/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhuver <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 22:10:12 by bhuver            #+#    #+#             */
/*   Updated: 2016/11/14 16:22:22 by bhuver           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

t_color			color_add(t_color u, t_color v)
{
	t_color		rgb;

	rgb.r = u.r + v.r;
	if (rgb.r > 255)
		rgb.r = 255;
	rgb.g = u.g + v.g;
	if (rgb.g > 255)
		rgb.g = 255;
	rgb.b = u.b + v.b;
	if (rgb.b > 255)
		rgb.b = 255;
	return (rgb);
}

t_color			color_stack(t_color u, t_color v)
{
	t_color		w;

	w.r = u.r + v.r;
	w.g = u.g + v.g;
	w.b = u.b + v.b;
	return (w);
}

t_color			color_mul(t_color color, double value)
{
	t_color		new;

	new.r = color.r * value;
	if (new.r > 255)
		new.r = 255;
	new.g = color.g * value;
	if (new.g > 255)
		new.g = 255;
	new.b = color.b * value;
	if (new.b > 255)
		new.b = 255;
	return (new);
}

t_color			color_new(int r, int g, int b)
{
	t_color		new;

	new.r = r;
	new.g = g;
	new.b = b;
	return (new);
}

void			put_pixel(t_env *e, t_color color, int x, int y)
{
	int			r;

	r = (x * e->win.bpp / 8) + (y * e->win.sl);
	if ((x < e->win.width && y < e->win.height &&
		x >= 0 && y >= 0))
	{
		(e->win.img_ptr)[r++] = !e->win.endian ? color.b : color.r;
		(e->win.img_ptr)[r++] = !e->win.endian ? color.g : color.b;
		(e->win.img_ptr)[r] = !e->win.endian ? color.r : color.g;
	}
}
