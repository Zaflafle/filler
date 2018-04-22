/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macuguen <macuguen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 00:15:21 by macuguen          #+#    #+#             */
/*   Updated: 2018/02/03 07:41:34 by macuguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	ret;
	unsigned int	j;

	i = ft_strlen(dst);
	ret = i + ft_strlen(src);
	j = 0;
	if (size < i)
		return (ft_strlen(src) + size);
	if (size > i + 1)
	{
		while (src[j] && j < size - i - 1)
		{
			dst[i + j] = src[j];
			j++;
		}
		dst[i + j] = '\0';
	}
	return (ret);
}
