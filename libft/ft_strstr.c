/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macuguen <macuguen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 21:46:30 by macuguen          #+#    #+#             */
/*   Updated: 2018/02/03 07:42:59 by macuguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strstr(const char *src, const char *str)
{
	int i;
	int j;
	int tmp;

	i = 0;
	j = 0;
	if (str[0] == '\0')
		return ((char*)src);
	while (src[i] != '\0')
	{
		if (str[j] == src[i])
		{
			tmp = i;
			while (str[j] != '\0' && src[tmp] != '\0')
			{
				if (str[j + 1] == '\0' && str[j] == src[tmp])
					return ((char*)&src[i]);
				tmp++;
				j++;
			}
			j = 0;
		}
		i++;
	}
	return (NULL);
}
