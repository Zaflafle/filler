/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macuguen <macuguen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 03:17:56 by macuguen          #+#    #+#             */
/*   Updated: 2018/02/03 07:41:57 by macuguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	int		i;
	int		len_s;

	i = 0;
	if (!s || !f)
		return (NULL);
	len_s = ft_strlen(s);
	if (!(str = (char*)malloc(sizeof(*str) * (len_s + 1))))
		return (NULL);
	while (i < len_s)
	{
		str[i] = f(s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
