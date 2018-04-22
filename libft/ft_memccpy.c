/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macuguen <macuguen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 23:11:43 by macuguen          #+#    #+#             */
/*   Updated: 2018/02/03 07:38:09 by macuguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*cast_src;
	unsigned char	*cast_dest;

	i = 0;
	cast_dest = (unsigned char *)dest;
	cast_src = (unsigned char *)src;
	while (i < n)
	{
		cast_dest[i] = cast_src[i];
		if (cast_dest[i] == (unsigned char)c)
			return (cast_dest + i + 1);
		i++;
	}
	return (NULL);
}
