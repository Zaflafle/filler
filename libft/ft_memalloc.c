/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macuguen <macuguen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 00:50:10 by macuguen          #+#    #+#             */
/*   Updated: 2018/02/03 07:38:03 by macuguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memalloc(size_t size)
{
	char *str;

	if (!size)
		return (NULL);
	if (!(str = (char*)malloc(sizeof(*str) * size)))
		return (NULL);
	ft_memset(str, 0, size);
	return ((void*)str);
}
