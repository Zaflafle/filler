/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macuguen <macuguen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 21:54:36 by macuguen          #+#    #+#             */
/*   Updated: 2018/02/03 07:42:54 by macuguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int	split_count_carac(char *str, int *tmp, char c)
{
	int j;

	j = 0;
	while (1)
	{
		if (str[*tmp] == c || str[*tmp] == '\0')
			return (j);
		j++;
		(*tmp)++;
	}
	return (0);
}

static int	split_count_param(char const *str, char c)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c && (i == 0 || str[i - 1] == c))
			j++;
		i++;
	}
	return (j);
}

static int	split_put_tab(char *str, char **split, char c)
{
	int i;
	int k;
	int j;
	int tmp;

	i = 0;
	k = 0;
	j = 0;
	tmp = 0;
	while (str[k] != '\0' && i < split_count_param(str, c))
	{
		while (str[k] == c)
			k++;
		tmp = k;
		if (!(split[i] = (char*)malloc(sizeof(char) *\
						(split_count_carac(str, &tmp, c) + 1))))
			return (0);
		while (k < tmp)
			split[i][j++] = str[k++];
		split[i][j] = '\0';
		j = 0;
		k++;
		i++;
	}
	return (0);
}

char		**ft_strsplit(char const *str, char c)
{
	char **split;

	if (str == NULL)
		return (NULL);
	else if (!(split = (char**)malloc(sizeof(char*) * \
					(split_count_param(str, c) + 1))))
		return (NULL);
	split[split_count_param((char*)str, c)] = NULL;
	split_put_tab((char*)str, split, c);
	return (split);
}
