/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhuver <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 15:28:36 by bhuver            #+#    #+#             */
/*   Updated: 2015/11/30 15:36:38 by bhuver           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t				ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t			len;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	len = ft_strlen(dst) + ft_strlen((char *)src);
	while (dst[i] && i < size)
		i++;
	if (i == size)
		return (ft_strlen((char *)src) + size);
	while (src[j] && i < size - 1)
		dst[i++] = src[j++];
	dst[i] = '\0';
	return (len);
}
