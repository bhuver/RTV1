/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhuver <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 15:52:00 by bhuver            #+#    #+#             */
/*   Updated: 2015/12/01 13:20:41 by bhuver           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	int			i;
	size_t		c;

	c = 0;
	if (!*s2)
		return ((char *)s1);
	while (s1[c] && c < n)
	{
		if (s1[c] == s2[0] && !(i = 0))
			while (s1[c + i] == s2[i] && s1[c + i] && (c + i) < n)
			{
				i++;
				if (!(s2[i]))
					return ((char *)s1 + c);
			}
		c++;
	}
	return (NULL);
}
