/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhuver <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 11:50:36 by bhuver            #+#    #+#             */
/*   Updated: 2015/12/01 15:46:43 by bhuver           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			is_delimiter(char c)
{
	return ((c == ' ' || c == '\t' || c == '\n') ? 1 : 0);
}

static int			getlen(const char *s)
{
	int				i;
	int				len;

	i = 0;
	len = (int)ft_strlen(s);
	while (s[i] && is_delimiter(s[i]))
	{
		i++;
		len--;
	}
	i = (int)ft_strlen(s) - 1;
	while (s[i] && is_delimiter(s[i]))
	{
		i--;
		len--;
	}
	return (len);
}

char				*ft_strtrim(char const *s)
{
	char			*newstr;
	int				len;
	int				i;
	int				j;

	if (!(i = 0) && !s)
		return (NULL);
	if (!is_delimiter(s[0]) && !is_delimiter(s[ft_strlen(s) - 1]))
		return (ft_strdup(s));
	len = getlen(s);
	while (s[i] && is_delimiter(s[i]))
		i++;
	if (!s[i])
		return ("");
	if (!(newstr = malloc(len + 1)))
		return (NULL);
	j = i;
	i = 0;
	while (i < len && s[i + j])
	{
		newstr[i] = s[i + j];
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}
