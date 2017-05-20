/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhuver <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 15:22:45 by bhuver            #+#    #+#             */
/*   Updated: 2015/12/01 12:36:56 by bhuver           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strncat(char *s1, const char *s2, size_t n)
{
	char			*tmp1;
	char			*tmp2;
	size_t			i;

	tmp1 = s1;
	tmp2 = (char *)s2;
	i = 0;
	while (*tmp1)
		tmp1++;
	while (*tmp2 && i < n)
	{
		*tmp1 = *tmp2;
		tmp1++;
		tmp2++;
		i++;
	}
	*tmp1 = '\0';
	return (s1);
}
