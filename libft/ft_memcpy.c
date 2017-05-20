/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhuver <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 13:11:44 by bhuver            #+#    #+#             */
/*   Updated: 2015/12/01 19:09:37 by bhuver           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void						*ft_memcpy(void *dst, const void *src, size_t n)
{
	const unsigned char		*source;
	unsigned char			*dest;

	source = (const unsigned char *)src;
	dest = (unsigned char *)dst;
	while (n--)
		*dest++ = *source++;
	return (dst);
}
