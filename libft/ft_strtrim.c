/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macuguen <macuguen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 21:04:50 by macuguen          #+#    #+#             */
/*   Updated: 2018/02/03 07:43:08 by macuguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strtrim(char const *s)
{
	int i;
	int len_s;

	if (s == NULL)
		return (NULL);
	len_s = ft_strlen(s);
	i = 0;
	while (s[len_s - 1] == ' ' || s[len_s - 1] == '\t' || s[len_s - 1] == '\n')
		len_s--;
	i = -1;
	while (s[++i] == ' ' || s[i] == '\t' || s[i] == '\n')
		len_s--;
	if (len_s <= 0)
		len_s = 0;
	return (ft_strsub(s, (unsigned int)i, (size_t)len_s));
}
