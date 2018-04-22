/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macuguen <macuguen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 04:24:01 by macuguen          #+#    #+#             */
/*   Updated: 2018/02/03 07:39:55 by macuguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char		*ft_realloc(char *str, char *src)
{
	int		i;
	int		j;
	int		size;
	char	*new;

	if (str == NULL)
		size = ft_strlen(src);
	else
		size = ft_strlen(str) + ft_strlen(src);
	i = 0;
	if (!(new = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (str && str[i] != '\0')
	{
		new[i] = str[i];
		i++;
	}
	j = 0;
	while (src[j] != '\0')
		new[i++] = src[j++];
	new[i] = '\0';
	if (str)
		free(str);
	return (new);
}
