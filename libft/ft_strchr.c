/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhuver <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 15:37:12 by bhuver            #+#    #+#             */
/*   Updated: 2015/12/01 13:38:31 by bhuver           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strchr(const char *s, int c)
{
	int			i;
	int			len;
	char		cp;

	i = 0;
	len = ft_strlen(s);
	cp = (char)c;
	if (!cp || !c)
		return ((char *)s + len);
	while (i <= len)
	{
		if (s[i] == cp)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}
