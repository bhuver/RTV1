/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhuver <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 23:57:45 by bhuver            #+#    #+#             */
/*   Updated: 2016/11/18 15:15:52 by bhuver           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float			ft_atof(const char *str)
{
	int			sign;
	float		i;
	float		value;
	int			exponent;

	i = 1;
	sign = 0;
	value = 0;
	while (ft_isblank(*str))
		str++;
	*str == '-' ? sign = 1 : 0;
	*str == '-' || *str == '+' ? str++ : 0;
	while ('0' <= *str && *str <= '9')
		value = value * 10 + (*str++ - '0');
	if (*str == '.' && (str++))
		while ('0' <= *str && *str <= '9')
			value += (*str++ - '0') / (i *= 10);
	if (*str == 'E' && (str++))
	{
		exponent = ft_atoi(str);
		if (exponent != 0)
			value = value * ft_pow(10, exponent);
	}
	return (sign == 1 && value > 0 ? -value : value);
}
