/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhuver <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 15:17:16 by bhuver            #+#    #+#             */
/*   Updated: 2015/12/01 12:27:47 by bhuver           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strcat(char *s1, const char *s2)
{
	char		*tmp1;
	char		*tmp2;

	tmp1 = s1;
	tmp2 = (char *)s2;
	while (*tmp1)
		tmp1++;
	while (*tmp2)
	{
		*tmp1 = *tmp2;
		tmp1++;
		tmp2++;
	}
	*tmp1 = '\0';
	return (s1);
}
