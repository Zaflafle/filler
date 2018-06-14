/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macuguen <macuguen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 15:15:31 by macuguen          #+#    #+#             */
/*   Updated: 2018/04/23 21:16:07 by macuguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "../../libft/includes/libft.h"

typedef struct	s_filler
{
	char player;
    int i;
    int j;
    int fd;
    int pr;
    char enemy;

    int nb_circle;
    int nb_point;

    int length_map_x;
    int length_map_y;
    int length_parts_x;
    int length_parts_y;

    int parts_x;
    int parts_y;

    int distance;
    int player_x;
    int player_y;
    int enemy_x;
    int enemy_y;

    int try_parts_x;
    int try_parts_y;
    int star;
}				t_filler;

typedef struct	s_co
{
    int x;
    int y;
}               t_co;

typedef struct	s_map
{
    char map_zero[15][17];
    char map_one[24][40];
    char map_two[100][99];

    char tmp_zero[15][17];
    char tmp_one[24][40];
    char tmp_two[100][99];

    char parts[100][99];
}	            t_map;
 

int     which_player(char *str);
void    length_of_the_map(char *str, t_filler *env);
void    length_of_the_parts(char *str, t_filler *env);
void    init_map_and_filling(char *str, t_filler *env, t_map *map);
void    filling_map_two(char *str, t_filler *env,  t_map *map);
void    filling_map_one(char *str, t_filler *env,  t_map *map);
void    filling_map_zero(char *str, t_filler *env, t_map *map);
void    init_parts_and_filling(char *str, t_filler *env, t_map *map);
void    ft_bzero_double(t_map *map, int n, int m);
void    parse_map_one(t_filler *env, t_map *map);
void    count_star(t_filler *env, t_map *map);
int     solveur(t_filler *env, t_map *map);
int     go_back(t_filler *env, t_map *map, int *src_x, int *src_y);
void    check_is_valid(t_filler *env, t_map *map);
void    first_star(t_filler *env, t_map *map);

#endif