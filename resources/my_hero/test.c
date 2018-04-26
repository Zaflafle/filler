/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macuguen <macuguen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 18:59:37 by macuguen          #+#    #+#             */
/*   Updated: 2018/04/26 20:52:22 by macuguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "filler.h"

// void    parse_parts(t_filler *env, t_map *map)
// {
//     while (x <= env->length_parts_x)

// }
void    go_back(t_filler *env, t_map *map)
{
    int x;
    int y;

    x = env->player_x;
    while (x >= 0)
    {
        y = env->player_y;
        while (y >= 0)
        {
            if (map->map_one[x][y] == 'O')
            {
                env->player_x = x;
                env->player_y = y;
            }
            y--;
        }
        x--;
    }
}

void    solveur(t_filler *env, t_map *map)
{
    int i;

    i = 0;
    while (i <= env->star)
    {
        if (i == 0 && map->map_one[env->player_x][env->player_y] == 'O')
            check_is_valid(env, map);
        else if (map->map_one[env->player_x + env->try_parts_x][env->player_y + env->try_parts_y] == '.')
            check_is_valid(env, map);
        else
        {
            i = 0;
            go_back(env, map);
        }
    }
        
}

void    count_star(t_filler *env, t_map *map)
{
    int x;
    int y;

    x = 0;
    y = 0;
    while (x <= env->length_parts_x)
    {
        y = 0;
        while (y <= env->length_parts_y)
        {
            if (map->parts[x][y] == '*')
                env->star++;
            y++;            
    }
}

void    check_is_valid(t_filler *env, t_map *map)
{
    int x;
    int y;

    x = env->try_parts_x;
    x = env->try_parts_y;
    while (x <= env->length_parts_x)
    {
        y = 0;
        while (map->parts[x][y] != '*')
            y++;
        if (map->parts[x][y] != '*')
        {
            env->try_parts_x = x;
            env->try_parts_y = y;
            break;
        }
    }
}

void    parse_map_one(t_filler *env, t_map *map)
{
    int x;
    int y;

    while (x <= 24)
    {
        y = 0;
        while (y <= 40)
        {
            if(map->map_one[x][y] == 'O')
            {
                env->player_x = x;
                env->player_y = y;
                env->distance = 0;
            }
            else if (map->map_one[x][y] == 'X')
            {
                env->enemy_x = x;
                env->enemy_y = y;                
                break;
            }
            env->distance++;
            y++;
        }
        x++;
    }
    dprintf(env->fd, "player_x = {%d} player_y = {%d} enemy_x = {%d} enemy_y = {%d} distance = {%d} \n",
    env->player_x, env->player_y, env->enemy_x, env->enemy_y, env->distance);
}

void    ft_bzero_double(t_map *map, int n, int m)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (i <= n)
    {
        ft_bzero(map->parts[i], (size_t)m);
        i++;
    }
}

void    init_parts_and_filling(char *str, t_filler *env, t_map *map)
{
    int i;
    int k;

    i = 0;
    k = 0;
    while (i <= env->length_parts_y)
    {
        map->parts[env->j][k] = str[i];
        i++;
        k++;
    }
   // dprintf(env->fd, "%d|%s|\n", env->j, map->parts[env->j]);    
}

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
   // dprintf(env->fd, "%d|%s|\n", env->j, map->map_one[env->j]);
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
    //dprintf(env->fd, "%d|%s|\n", env->j, map->map_one[env->j]);
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
    //dprintf(env->fd, "%d|%s|\n", env->j, map->map_one[env->j]);
}

void    init_map_and_filling(char *str, t_filler *env, t_map *map)
{
    if (env->length_map_x == 15 && env->length_map_y == 17)
        filling_map_zero(str, env, map);
    else if (env->length_map_x == 24 && env->length_map_y == 40)
        filling_map_one(str, env, map);
    else if (env->length_map_x == 100 && env->length_map_y == 99)
        filling_map_two(str, env, map);

}

void length_of_the_parts(char *str, t_filler *env)
{
    int i;

    i = 0;
    while (ft_isdigit(str[i]) != 1)
        i++;
    env->length_parts_x = ft_atoi(&str[i]);
    i = i + 2;
    while (ft_isdigit(str[i]) != 1)
        i++;
    env->length_parts_y = ft_atoi(&str[i]);
    dprintf(env->fd, "length_parts_x = {%d} length_parts_y = {%d}\n", env->length_parts_x, env->length_parts_y);
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
            if (ft_strncmp("Piece", str, 5) == 0)
            {
                length_of_the_parts(str, &env);
                env.j = 0; 
                ft_bzero_double(&map, env.length_parts_x, env.length_parts_y);
                    get_next_line(0, &str);                
                while (env.j <= env.length_parts_x)
                {
                    dprintf(env.fd, "%s\n", str);
                    init_parts_and_filling(str, &env, &map);
                    get_next_line(0, &str);
                    env.j++;
                }
            }
            parse_map_one(&env, &map);
            // printf("4 4\n");
        }
        env.i++;
        dprintf(env.fd, "%s\n", str);
    }
    env.fd = close(env.fd);
    return (0);
}