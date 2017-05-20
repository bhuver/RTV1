/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhuver <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 13:13:33 by bhuver            #+#    #+#             */
/*   Updated: 2015/12/02 16:51:05 by bhuver           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	const unsigned char		*buff1;
	unsigned char			*buff2;

	buff1 = (const unsigned char *)src;
	buff2 = (unsigned char *)dst;
	if (n > 0)
	{
		while (*buff1 != (unsigned char)c && n)
		{
			*buff2++ = *buff1++;
			--n;
		}
		if (*buff1 == (unsigned char)c && n)
			*buff2++ = *buff1;
		return ((n == 0) ? 0 : buff2);
	}
	return (0);
}
