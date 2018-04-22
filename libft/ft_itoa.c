/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macuguen <macuguen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 03:53:40 by macuguen          #+#    #+#             */
/*   Updated: 2018/02/03 07:36:57 by macuguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_itoa(int n)
{
	char	*str;
	int		tmp_n;
	int		i;
	int		neg;

	tmp_n = n;
	i = 1;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	neg = ft_is_neg(&n);
	while (tmp_n /= 10)
		i++;
	if (!(str = (char*)malloc(sizeof(*str) * (i + 1 + neg))))
		return (NULL);
	i = i + neg;
	str[i--] = '\0';
	while (i >= 0)
	{
		str[i] = n % 10 + '0';
		n = n / 10;
		i--;
	}
	if (neg == 1)
		str[0] = '-';
	return (str);
}
