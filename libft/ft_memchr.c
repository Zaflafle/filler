/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macuguen <macuguen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 23:11:54 by macuguen          #+#    #+#             */
/*   Updated: 2018/02/03 07:38:13 by macuguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*cast_s;
	unsigned int	cast_c;

	if (!s && !c && !n)
		return (0);
	i = 0;
	cast_s = (unsigned char*)s;
	cast_c = (unsigned char)c;
	while (i < n)
	{
		if (cast_c == cast_s[i])
			return (cast_s + i);
		i++;
	}
	return (NULL);
}
