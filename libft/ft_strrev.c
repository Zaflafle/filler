/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macuguen <macuguen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 00:38:37 by macuguen          #+#    #+#             */
/*   Updated: 2018/02/03 07:42:50 by macuguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strrev(char *str)
{
	int i;
	int j;
	int c;

	c = 0;
	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	j = i - 1;
	while (c < (i / 2))
	{
		ft_swap_char(&str[c], &str[j]);
		c++;
		j--;
	}
	return (str);
}
