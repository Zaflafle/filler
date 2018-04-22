/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macuguen <macuguen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 23:12:35 by macuguen          #+#    #+#             */
/*   Updated: 2018/02/03 07:38:29 by macuguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*cast_dest;
	char	*cast_src;
	size_t	i;

	cast_dest = (char*)dest;
	cast_src = (char*)src;
	i = 0;
	if (cast_src < cast_dest)
	{
		while (n--)
			cast_dest[n] = cast_src[n];
	}
	else
		ft_memcpy(cast_dest, cast_src, n);
	return (cast_dest);
}
