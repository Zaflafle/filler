/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_other.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macuguen <macuguen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 06:41:30 by macuguen          #+#    #+#             */
/*   Updated: 2018/02/03 07:40:48 by macuguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strdup_other(char *src, int size)
{
	char	*str;
	int		i;

	i = 0;
	str = NULL;
	if (!(str = ft_memalloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (src[i] != '\0' && src[i] != '\n')
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
