/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhuver <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 17:50:34 by bhuver            #+#    #+#             */
/*   Updated: 2016/11/18 16:33:28 by bhuver           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

void		exit_rt(t_env *e)
{
	t_obj	*tmp;

	tmp = e->objs;
	while (tmp)
	{
		e->objs = tmp->next;
		free(tmp);
		tmp = e->objs;
	}
	exit(-1);
}

int			mexpose(t_env *e)
{
	raycast(e);
	mlx_put_image_to_window(e->win.mlx, e->win.win, e->win.img, 0, 0);
	return (1);
}

int			key_h(int k, t_env *e)
{
	k == 53 ? exit_rt(e) : 0;
	mexpose(e);
	return (1);
}
