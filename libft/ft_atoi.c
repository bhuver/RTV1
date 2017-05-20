/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhuver <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 16:49:39 by bhuver            #+#    #+#             */
/*   Updated: 2015/11/30 16:54:30 by bhuver           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_atoi(const char *str)
{
	int			i;
	int			res;
	int			neg;

	i = 0;
	res = 0;
	neg = 0;
	while (str[i] == ' ' || (str[i] > 8 && str[i] < 14))
		i++;
	if (str[i] == '-' || str[i] == '+')
		(str[i++] == '-') ? neg = 1 : neg;
	while (ft_isdigit(str[i]))
		res = (res * 10) + str[i++] - 48;
	(neg == 1) ? res *= -1 : res;
	return (res);
}
