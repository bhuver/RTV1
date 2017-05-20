/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhuver <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 14:01:01 by bhuver            #+#    #+#             */
/*   Updated: 2015/12/02 16:53:35 by bhuver           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char		*buff;
	size_t				i;

	i = 0;
	buff = (unsigned char *)s;
	if (i < n)
	{
		while (i < n && buff[i] != (unsigned char)c)
			i++;
		if (i < n && buff[i] == (unsigned char)c)
			return ((void *)buff + i);
	}
	return (NULL);
}
