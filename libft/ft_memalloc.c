/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhuver <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 17:35:15 by bhuver            #+#    #+#             */
/*   Updated: 2015/12/01 12:21:08 by bhuver           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memalloc(size_t size)
{
	void			*new;

	new = (void *)malloc(size * sizeof(size_t));
	if (new == NULL)
		return (NULL);
	else
	{
		ft_memset(new, 0, size);
		return (new);
	}
}
