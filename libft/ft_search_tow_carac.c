/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_tow_carac.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macuguen <macuguen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 23:44:39 by macuguen          #+#    #+#             */
/*   Updated: 2018/02/03 07:40:02 by macuguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_search_tow_carac(char *str, char c, char d)
{
	int i;

	i = 0;
	while (str[i] != c && str[i] != d)
	{
		i++;
		if (str[i] == c)
			return (1);
	}
	return (0);
}
