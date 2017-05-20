/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhuver <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 14:12:12 by bhuver            #+#    #+#             */
/*   Updated: 2016/01/26 15:44:25 by bhuver           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strdup(const char *s1)
{
	size_t		len;
	size_t		i;
	char		*new_str;

	len = ft_strlen(s1);
	if (!(new_str = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (i < len)
	{
		*(new_str + i) = *(s1 + i);
		i++;
	}
	*(new_str + len) = '\0';
	return (new_str);
}
