/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macuguen <macuguen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 21:07:52 by macuguen          #+#    #+#             */
/*   Updated: 2018/02/03 07:37:36 by macuguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *prev;
	t_list *first;

	first = NULL;
	while (lst)
	{
		new = f(lst);
		if (first == NULL)
			first = new;
		else
			prev->next = new;
		prev = new;
		lst = lst->next;
	}
	prev->next = NULL;
	return (first);
}
