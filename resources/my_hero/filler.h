/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macuguen <macuguen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 15:15:31 by macuguen          #+#    #+#             */
/*   Updated: 2018/04/22 21:26:25 by macuguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "../../libft/includes/libft.h"

typedef struct	s_filler
{
	int player;
    int i;
    int j;
    int fd;
    int length_map_x;
    int length_map_y;
}				t_filler;

typedef struct	s_map
{
    char map_zero[15][17];
    char map_one[24][40];
    char map_two[100][99];
}	            t_map;
 
#endif      