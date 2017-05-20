/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhuver <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 17:39:11 by bhuver            #+#    #+#             */
/*   Updated: 2016/01/26 16:01:53 by bhuver           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strnew(size_t size)
{
	char			*newstr;
	unsigned int	i;
	unsigned int	nb_char;

	if (!(newstr = (char*)malloc(size)))
		return (NULL);
	nb_char = size / sizeof(char);
	i = 0;
	while (i < nb_char)
	{
		*(newstr + i) = '\0';
		i++;
	}
	return (newstr);
}
