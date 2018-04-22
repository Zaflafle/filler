/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_wchar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macuguen <macuguen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 03:27:39 by macuguen          #+#    #+#             */
/*   Updated: 2018/02/22 03:51:47 by macuguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

wchar_t	*ft_strdup_wchar(const wchar_t *src)
{
	wchar_t			*str;
	unsigned int	len;
	int				i;

	i = 0;
	len = ft_strlen_w(src);
	if (!(str = (wchar_t*)malloc((len + 2))))
		return (NULL);
	while (src[i] != '\0')
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
