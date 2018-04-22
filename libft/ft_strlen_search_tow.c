/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_search_tow.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macuguen <macuguen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 00:24:59 by macuguen          #+#    #+#             */
/*   Updated: 2018/02/03 07:41:44 by macuguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_strlen_search_tow(char *str, char c, char d)
{
	int i;

	i = 0;
	while (str[i] != c && str[i] != d && str[i] != '\0')
		i++;
	return (i);
}
