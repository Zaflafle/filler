/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macuguen <macuguen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 04:31:33 by macuguen          #+#    #+#             */
/*   Updated: 2018/02/03 07:42:02 by macuguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;
	size_t			len_s;

	i = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	len_s = ft_strlen(s);
	if (!(str = (char*)malloc(sizeof(*str) * (len_s + 1))))
		return (NULL);
	str[len_s] = '\0';
	while (i < len_s)
	{
		str[i] = f(i, s[i]);
		i++;
	}
	return (str);
}
