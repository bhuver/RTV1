/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhuver <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 16:47:09 by bhuver            #+#    #+#             */
/*   Updated: 2015/12/01 17:32:30 by bhuver           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list		*tmp;

	tmp = *alst;
	if (*alst && del)
		while (*alst)
		{
			tmp = (*alst)->next;
			ft_lstdelone(alst, del);
			*alst = tmp;
		}
}
