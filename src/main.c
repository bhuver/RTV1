/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-la-s <vde-la-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 19:35:51 by bhuver            #+#    #+#             */
/*   Updated: 2016/11/18 14:39:01 by bhuver           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

static void			init_mlx(t_env *e)
{
	e->win.mlx = mlx_init();
	e->win.width = WIDTH;
	e->win.height = HEIGHT;
	e->win.img = mlx_new_image(e->win.mlx, e->win.width, e->win.height);
	e->win.img_ptr = mlx_get_data_addr(e->win.img, &(e->win.bpp),
									&(e->win.sl), &(e->win.endian));
	e->win.win = mlx_new_window(e->win.mlx, WIDTH, HEIGHT, "RTV1");
	mlx_hook(e->win.win, 2, 1, key_h, e);
	mlx_expose_hook(e->win.win, mexpose, e);
	if (!(e->win.win))
		exit(-1);
}

static void			init_scene(t_env *e)
{
	e->objs = NULL;
	e->lgt.pos = vec_new(0, 10, -10);
	e->lgt.intensity = 0.5;
	e->lgt.col = color_new(255, 255, 255);
	e->cam.pos = vec_new(0, 0, -10);
	e->cam.dir = vec_new(0, 0, 1);
	e->cam.view_d = 1.5;
	e->cam.view_h = 1.4;
	e->cam.view_w = 2.4;
	e->cam.x_ind = e->cam.view_w / (float)WIDTH;
	e->cam.y_ind = e->cam.view_h / (float)HEIGHT;
	e->cam.up = vec_new(0, 1, 0);
}

static void			init(t_env *e, char *filename)
{
	init_mlx(e);
	init_scene(e);
	read_file(e, filename);
	e->cam.right = cross_pr(e->cam.up, e->cam.dir);
	e->cam.up_left = vec_add(e->cam.pos,
							vec_add(vec_cmul(e->cam.dir, e->cam.view_d),
									vec_sub(vec_cmul(e->cam.up,
													(e->cam.view_h / 2.0)),
											vec_cmul(e->cam.right,
													(e->cam.view_w /
													2.0)))));
}

int					main(int ac, char **av)
{
	t_env			e;

	if (ac == 2)
	{
		init(&e, av[1]);
		raycast(&e);
		mlx_loop(e.win.mlx);
	}
	else
		ft_putendl_fd("USE: ./rtv1 [filename]", 2);
	return (1);
}
