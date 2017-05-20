/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhuver <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 18:41:41 by bhuver            #+#    #+#             */
/*   Updated: 2016/01/26 15:51:32 by bhuver           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*sub_str;
	unsigned int	i;

	if (!(sub_str = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = start;
	while (i < start + len)
	{
		sub_str[i - start] = s[i];
		i++;
	}
	sub_str[len] = '\0';
	return (sub_str);
}
