/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhuver <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 13:05:48 by bhuver            #+#    #+#             */
/*   Updated: 2016/01/26 15:52:53 by bhuver           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memset(void *b, int c, size_t len)
{
	unsigned int	i;
	unsigned char	*mzone;

	mzone = b;
	i = 0;
	while (i < len)
	{
		*(mzone + i) = (unsigned char)c;
		i++;
	}
	return (b);
}
