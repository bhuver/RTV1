/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.pars.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhuver <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 00:02:45 by bhuver            #+#    #+#             */
/*   Updated: 2016/11/18 15:25:46 by bhuver           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

int			ft_isin(char *e, char *s)
{
	int		i;
	int		j;

	i = -1;
	while (s[++i])
	{
		j = 0;
		while (s[i + j] && e[j] && s[i + j] == e[j])
			++j;
		if (!e[j])
			return (1);
	}
	return (0);
}

float		get_fafter(char c, char *s)
{
	int		i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	if (s[i] && s[i] == c)
		return (ft_atof(&s[i + 1]));
	return (0);
}

float		get_iafter(char c, char *s)
{
	int		i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	if (s[i] && s[i] == c)
		return (ft_atoi(&s[i + 1]));
	return (0);
}

t_color		read_color(char *s)
{
	int		i;
	t_color	col;

	i = 0;
	while (s[i] && s[i] != ':')
		i++;
	col.r = get_iafter(':', &s[i++]);
	while (s[i] && s[i] != ';')
		i++;
	col.g = get_iafter(';', &s[i++]);
	while (s[i] && s[i] != ';')
		i++;
	col.b = get_iafter(';', &s[i]);
	return (col);
}

t_vect		read_vector(char *s)
{
	int		i;
	t_vect	vec;

	i = 0;
	while (s[i] && s[i] != ':')
		i++;
	vec.x = get_fafter(':', &s[i++]);
	while (s[i] && s[i] != ';')
		i++;
	vec.y = get_fafter(';', &s[i++]);
	while (s[i] && s[i] != ';')
		i++;
	vec.z = get_fafter(';', &s[i]);
	return (vec);
}
