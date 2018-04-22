/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_w.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macuguen <macuguen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 03:18:51 by macuguen          #+#    #+#             */
/*   Updated: 2018/04/05 18:03:43 by macuguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include "stdio.h"

size_t			ft_strlen_w(const wchar_t *str)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		j = j + ft_count_bit_w(str[i]);
		i++;
	}
	return (j);
}
