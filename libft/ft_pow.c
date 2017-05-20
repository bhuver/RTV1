/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhuver <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 15:12:18 by bhuver            #+#    #+#             */
/*   Updated: 2016/11/18 15:12:49 by bhuver           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float		ft_pow(double nb, int expo)
{
	float	result;

	result = 1;
	while (expo > 0)
	{
		result = result * nb;
		expo--;
	}
	while (expo < 0)
	{
		result = result / nb;
		expo++;
	}
	return (result);
}
