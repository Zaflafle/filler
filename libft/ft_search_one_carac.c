/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_one_carac.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macuguen <macuguen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 09:18:31 by macuguen          #+#    #+#             */
/*   Updated: 2018/02/03 07:39:58 by macuguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_search_one_carac(char *str, char c)
{
	int i;

	i = 0;
	if (str && str[i] == c)
		return (1);
	while (str && str[i] != c && str[i] != '\0')
	{
		i++;
		if (str[i] == c)
			return (1);
	}
	return (0);
}
