/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhuver <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 12:50:03 by bhuver            #+#    #+#             */
/*   Updated: 2016/01/15 13:48:48 by bhuver           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	l1;
	unsigned int	l2;
	unsigned int	i;
	char			*new_str;

	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	if (!(new_str = (char*)malloc(sizeof(char) * (l1 + l2 + 1))))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		new_str[i] = s1[i];
		i++;
	}
	while (s2[i - l1])
	{
		new_str[i] = s2[i - l1];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
