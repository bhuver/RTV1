/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhuver <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 17:30:37 by bhuver            #+#    #+#             */
/*   Updated: 2016/03/23 15:01:02 by bhuver           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			count_words(char const *s, char c)
{
	int				nb;
	int				i;

	nb = 0;
	i = 0;
	if (s[i] && s[i] != c)
		nb++;
	while (s[i])
		if (s[i] == c)
			while (s[i] == c && s[i])
			{
				if (s[++i] && s[i] != c)
					nb++;
			}
		else
			i++;
	return (nb);
}

static char			**allocate_x(char **tab, int size, char const *s, char c)
{
	int				y;
	int				i;
	int				save;

	y = 0;
	i = 0;
	while (s[i] == c)
		i++;
	save = i;
	while (y < size)
	{
		while (s[i] && s[i] != c)
			i++;
		if (s[i] == c || s[i] == '\0')
		{
			tab[y] = (char *)malloc(((i - save) + 1) * sizeof(char));
			if (!tab[y])
				return (NULL);
			while (s[i] == c)
				i++;
			save = i;
			y++;
		}
	}
	return (tab);
}

static char			**fill_tab_x(char **tab, int size, char const *s, char c)
{
	int				y;
	int				x;
	int				i;

	y = 0;
	x = 0;
	i = 0;
	while (s[i] == c)
		i++;
	while (y < size)
	{
		while (s[i] && s[i] != c)
			tab[y][x++] = s[i++];
		if (s[i] == c || s[i] == '\0')
		{
			while (s[i] == c)
				i++;
			tab[y][x] = '\0';
			x = 0;
			y++;
		}
	}
	return (tab);
}

static int			check_letters(char const *s, char c)
{
	int				i;

	i = 0;
	while (s[i] && (ft_isdigit(s[i]) || s[i] == '-' || s[i] == c))
		i++;
	return (s[i] == 0 ? 1 : 0);
}

char				**ft_strsplit(char const *s, char c)
{
	char			**tab;
	int				tabsize;

	if (!check_letters(s, c))
	{
		ft_putendl("Invalid map");
		exit(-1);
	}
	tabsize = count_words(s, c);
	tab = (char **)malloc((tabsize + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	tab[tabsize] = 0;
	tab = allocate_x(tab, tabsize, s, c);
	tab = fill_tab_x(tab, tabsize, s, c);
	return (tab);
}
