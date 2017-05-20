/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhuver <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 18:22:02 by bhuver            #+#    #+#             */
/*   Updated: 2015/11/25 18:34:06 by bhuver           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strmap(char const *s, char (*f)(char))
{
	char			*newstr;
	int				len;

	len = 0;
	while (s[len])
		len++;
	newstr = (char *)malloc((len + 1) * sizeof(char));
	if (!newstr)
		return (NULL);
	len = 0;
	while (s[len])
	{
		newstr[len] = f(s[len]);
		len++;
	}
	newstr[len] = '\0';
	return (newstr);
}
