/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhuver <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 16:04:24 by bhuver            #+#    #+#             */
/*   Updated: 2016/11/18 18:33:09 by bhuver           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYTRACER_H
# define RAYTRACER_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "mlx.h"
# include "libft.h"
# include "get_next_line.h"

# define WIDTH	1280
# define HEIGHT	720
# define EPSILON 0.001

# define SPHERE		42
# define PLAN		43
# define CYLINDRE	44
# define CONE		45

# define SQ(x) ((x) * (x))

typedef struct			s_color
{
	int					r;
	int					g;
	int					b;
}						t_color;

typedef struct			s_vect
{
	float				x;
	float				y;
	float				z;
}						t_vect;

typedef struct			s_cam
{
	t_vect				pos;
	t_vect				dir;
	t_vect				right;
	t_vect				up;
	t_vect				up_left;
	float				view_d;
	float				view_h;
	float				view_w;
	float				x_ind;
	float				y_ind;
}						t_cam;

typedef struct			s_ray
{
	t_vect				orig;
	t_vect				dir;
	t_vect				norm;
	t_vect				hit_point;
	float				solut;
	struct s_obj		*obj_hit;
}						t_ray;

typedef struct			s_mlx
{
	void				*mlx;
	void				*win;
	void				*img;
	char				*img_ptr;
	int					sl;
	int					endian;
	int					bpp;
	int					width;
	int					height;
}						t_mlx;

typedef struct			s_mat
{
	t_color				col;
	float				dif;
}						t_mat;

typedef struct			s_lgt
{
	float				intensity;
	t_vect				pos;
	t_color				col;
}						t_lgt;

typedef struct			s_obj
{
	t_vect				pos;
	t_vect				dir;
	t_vect				norm;
	int					type;
	int					rayon;
	float				alpha;
	t_mat				mat;
	struct s_obj		*next;
}						t_obj;

typedef struct			s_env
{
	t_lgt				lgt;
	t_mlx				win;
	t_cam				cam;
	t_ray				ray;
	t_obj				*objs;
}						t_env;

t_color					color_add(t_color u, t_color v);
t_color					color_stack(t_color u, t_color v);
t_color					color_mul(t_color c, double i);
t_color					color_new(int r, int g, int b);
void					put_pixel(t_env *e, t_color color, int x, int y);
float					int_cone(t_obj *o, t_ray ray);
float					int_cylindre(t_obj *o, t_ray ray);
float					int_sphere(t_obj *o, t_ray ray);
float					int_plan(t_obj *o, t_ray ray);
void					int_objs(t_env *e);
t_obj					*push_obj(t_env *e);
void					raycast(t_env *e);
t_vect					vec_mrot(t_vect a, t_vect b);
float					vec_dot(t_vect a, t_vect b);
float					dist_p(t_vect u, t_vect v);
t_vect					vec_normalize(t_vect a);
t_vect					vec_new(float x, float y, float z);
t_vect					vec_add(t_vect a, t_vect b);
t_vect					vec_sub(t_vect a, t_vect b);
t_vect					vec_mul(t_vect a, t_vect b);
t_vect					vec_cmul(t_vect a, float b);
t_vect					cross_pr(t_vect u, t_vect v);
t_color					render_light(t_env *e);
int						mexpose(t_env *e);
int						key_h(int k, t_env *e);
void					read_file(t_env *e, char *filename);
t_vect					read_vector(char *s);
t_color					read_color(char *s);
float					get_iafter(char c, char *s);
float					get_fafter(char c, char *s);
int						ft_isin(char *s, char *e);

#endif
