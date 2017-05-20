/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhuver <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 12:36:47 by bhuver            #+#    #+#             */
/*   Updated: 2015/12/01 12:23:14 by bhuver           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_abs(int n)
{
	return ((n < 0) ? -n : n);
}

char			*ft_itoa(int n)
{
	int			size;
	int			nb;
	char		*str;

	size = (n < 0) ? 2 : 1;
	nb = n;
	while (nb > 9 || nb < -9)
	{
		size++;
		nb = ft_abs(nb / 10);
	}
	if ((str = (char *)malloc((size + 1) * sizeof(char))))
	{
		str[size--] = '\0';
		nb = n;
		while (size + 1)
		{
			str[size--] = '0' + ft_abs(nb % 10);
			nb = ft_abs(nb / 10);
		}
		if (n < 0)
			str[0] = '-';
	}
	return (str);
}
