/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhuver <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 17:04:51 by bhuver            #+#    #+#             */
/*   Updated: 2015/12/01 19:06:45 by bhuver           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*tmp;
	t_list		*new;

	new = NULL;
	while (lst)
	{
		if (!new)
		{
			new = f(lst);
			tmp = new;
			tmp->next = NULL;
		}
		else
		{
			tmp->next = f(lst);
			tmp = tmp->next;
			tmp->next = NULL;
		}
		lst = lst->next;
	}
	return (new);
}
