/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_bit_w.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macuguen <macuguen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 21:27:32 by macuguen          #+#    #+#             */
/*   Updated: 2018/04/04 19:26:41 by macuguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

size_t	ft_count_bit_w(wchar_t c)
{
	unsigned int	e;

	e = (unsigned int)c;
	if (e <= 128)
		return (1);
	else if (e <= 0x07FF)
		return (2);
	else if (e <= 0xFFFF)
		return (3);
	else
		return (4);
}
