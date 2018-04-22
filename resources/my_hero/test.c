/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macuguen <macuguen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 18:59:37 by macuguen          #+#    #+#             */
/*   Updated: 2018/04/22 23:30:28 by macuguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "filler.h"

void    filling_map_zero(char *str, t_filler *env, t_map *map)
{
    int i;
    int k;

    i = 4;
    k = 0;
    while (i <= 21)
    {
        map->map_one[env->j][k] = str[i];
        i++;
        k++;
    }
    dprintf(env->fd, "%d|%s|\n", env->j, map->map_one[env->j]);
}
void    filling_map_one(char *str, t_filler *env,  t_map *map)
{
    int i;
    int k;

    i = 4;
    k = 0;
    while (i <= 44)
    {
        map->map_one[env->j][k] = str[i];
        i++;
        k++;
    }
    dprintf(env->fd, "%d|%s|\n", env->j, map->map_one[env->j]);
}
void    filling_map_two(char *str, t_filler *env,  t_map *map)
{
    int i;
    int k;

    i = 4;
    k = 0;
    while (i <= 103)
    {
        map->map_one[env->j][k] = str[i];
        i++;
        k++;
    }
    dprintf(env->fd, "%d|%s|\n", env->j, map->map_one[env->j]);
}

void    init_map_and_filling(char *str, t_filler *env, t_map *map)
{
    if (env->length_map_x == 15 && env->length_map_y == 17)
        filling_map_zero(str, env, map);
    // else if (env->length_map_x == 24 && env->length_map_y == 40)
    //     filling_map_one(str, env, map);
    // else if (env->length_map_x == 100 && env->length_map_y == 99)
    //     filling_map_two(str, env, map);

}


void length_of_the_map(char *str, t_filler *env)
{
    int i;

    i = 0;
    while (ft_isdigit(str[i]) != 1)
        i++;
    env->length_map_x = ft_atoi(&str[i]);
    i = i + 3;
    while (ft_isdigit(str[i]) != 1)
        i++;
    env->length_map_y = ft_atoi(&str[i]);
    dprintf(env->fd, "length_map_x = {%d} length_map_y = {%d} player = {%d}\n", env->length_map_x, env->length_map_y, env->player);
}

int which_player(char *str)
{
    char *player_one;
    char *player_two;

    player_one = "$$$ exec p1 : [my_hero/lala.filler]";
    player_two = "$$$ exec p2 : [my_hero/lala.filler]";
    if (ft_strcmp(player_one, str) == 0)
        return (1);
    else if (ft_strcmp(player_two, str) == 0)
        return (2);
    else
        return (0);
}

int main()
{
    char        *str;
    t_filler	env;
    t_map       map;

    ft_bzero(&env, sizeof(t_filler));
	ft_bzero(&map, sizeof(t_map));    
    env.fd = open("parse", O_RDWR | O_APPEND);
    str = NULL;
    while (42)
    {
        get_next_line(0, &str);
        if (env.i == 0)
            env.player = which_player(str);
        else if (env.i == 1)
            length_of_the_map(str, &env);
        else if (ft_strncmp("000", str, 3) == 0)
        {
            env.j = 0;            
            while (ft_strncmp("Piece", str, 5) != 0)
            {
                dprintf(env.fd, "%s\n", str);
                init_map_and_filling(str, &env, &map);
                get_next_line(0, &str);                
                env.j++;
            }
        }
        env.i++;
        dprintf(env.fd, "%s\n", str);
    }
    env.fd = close(env.fd);
    return (0);
}