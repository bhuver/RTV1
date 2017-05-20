/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhuver <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 13:38:22 by bhuver            #+#    #+#             */
/*   Updated: 2015/12/01 13:45:42 by bhuver           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memmove(void *dst, const void *src, size_t len)
{
	void			*swap;

	swap = (void *)malloc(len);
	if (swap)
	{
		ft_memcpy(swap, src, len);
		ft_memcpy(dst, swap, len);
		free(swap);
		return (dst);
	}
	return (NULL);
}
