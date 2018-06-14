/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macuguen <macuguen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 18:59:37 by macuguen          #+#    #+#             */
/*   Updated: 2018/06/14 18:23:23 by macuguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "filler.h"

void    first_star(t_filler *env, t_map *map)
{
    int x;
    int y;

    x = 0;
    y = 0;
    while (x <= env->length_parts_x)
    {
        y = 0;
        while (y < env->length_parts_y)
        {
            if (map->parts[x][y] == '*')
            {
                env->parts_x = x;
                env->parts_y = y;
                return;
            }
            y++;
        }
        x++;
    }
}

void    count_star(t_filler *env, t_map *map)
{
    int x;
    int y;

    x = 0;
    y = 0;
    env->star = 0;
    while (x < env->length_parts_x)
    {
        y = 0;
        while (y <= env->length_parts_y)
        {
            if (map->parts[x][y] == '*')
                env->star++;
            dprintf(env->fd, "ICI env->length_parts_x = %d env->length_parts_y = %d env->star = %d\n", env->length_parts_x, env->length_parts_y, env->star);            
            y++;
        }
        x++;    
    }
}

void        check_star(t_filler *env, t_map *map)
{
    int x;
    int y;

    x = 0;
    y = 0;
    if (env->try_parts_y  == env->length_parts_y && env->try_parts_x <= env->try_parts_x)
    {
        dprintf(env->fd,"ICI 1\n");
        x++;
        y = 0;
    }
    else if (env->j == 0)
    {
        x = env->try_parts_x;
        y = env->try_parts_y;
    }
    else
    {
        dprintf(env->fd,"ICI 2\n");
        x = env->try_parts_x;
        y = env->try_parts_y + 1;
    }
    while (x <= env->length_parts_x)
    {
        while (y < env->length_parts_y)
        {
            if (map->parts[x][y] == '*')
            {
                env->try_parts_x = x;
                env->try_parts_y = y;
                env->j++;
                return;
            }
            y++;
        }
        y = 0;        
        x++;
    }
}

int        check_pisition(t_filler *env, t_map *map,int map_x, int map_y)
{
    int x;
    int y;

    x = 0;
    y = 0;
    env->nb_circle = 0;
    env->nb_point = 0;
    while (x < env->length_parts_x && (map_x + x) < env->length_map_x)
    {
            while (y < env->length_parts_y && (map_y + y) < env->length_map_y)
            {
                    if (y + map_y > env->length_map_y)
                    {
                        if (map->parts[x][y] == '*' && map->map_two[x + map_x][y + map_y - env->length_map_y] == env->player)
                            env->nb_circle++;
                        else if (map->parts[x][y] == '*' && map->map_two[x + map_x][map_y + y - env->length_map_y]  == '.')
                            env->nb_point++;
                    }
                    else if (y + map_y < 0)
                    {
                        if (map->parts[x][y] == '*' && map->map_two[x + map_x][y + map_y + env->length_map_y] == env->player)
                            env->nb_circle++;
                        else if (map->parts[x][y] == '*' && map->map_two[x + map_x][map_y + y + env->length_map_y]  == '.')
                            env->nb_point++;
                    }
                    else
                    {
                        if (map->parts[x][y] == '*' && map->map_two[x + map_x][y + map_y] == env->player)
                            env->nb_circle++;
                        else if (map->parts[x][y] == '*' && map->map_two[x + map_x][map_y + y]  == '.')
                            env->nb_point++;
                    }
                y++;
            }
            y = 0;
        x++;
    }
    if (env->nb_circle == 1 && env->nb_point == env->star - 1)
    { 
        dprintf(env->fd, "%d|%c |%d|%c|\n",map_x, map->map_two[map_x][map_y], map_y, map->map_two[map_x][map_y]);
        dprintf(env->fd,"SORTIE 1 CHECK POSITION\n");
        return (0);
    }
    return (-1);
}

int         two_map_comp(t_filler *env, t_map *map)
{
    int i;
    int j;

    i = 0;
    while (i <= env->length_map_x)
    {
        j = 0;
        while (j <= env->length_map_y)
        {
            //dprintf(env->fd, "%d map_one = %c tmp_one = %c\n",j , map->map_two[i][j],map->tmp_one[i][j]);         
            if (map->map_two[i][j] != map->tmp_two[i][j] && map->map_two[i][j] == env->enemy)
            {
                dprintf(env->fd, "j = %d, i = %d\n\n", j,i);
                env->enemy_x = i;
                env->enemy_y = j;
                return (0);
            }
            j++;
        }
        i++;
    }
    return (-1);
}

int     ft_abs(int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

int       best_choice(t_filler *env, t_co *co, int nb)
{
    int i;
    int distance_x;
    int distance_y;
    int name;

    distance_x = 100;
    distance_y = 100;
    i = 0;
    name = -1;
    while (i < nb)
    {
        // if (co[i].x < 0)
        //     co[i].x = co[i].x * -1;
        // if (co[i].y < 0)
        //     co[i].y = co[i].y * -1;
        dprintf(env->fd, "i = %d co[i].x = %d, co[i].y = %d, enemy_x = %d, enemy_y = %d, distance_x = %d, distance_y = %d r_y = %d, r_x = %d\n\n",
         i, co[i].x,co[i].y, env->enemy_x, env->enemy_y, ft_abs(distance_x), ft_abs(distance_y), ft_abs(co[i].y) - ft_abs(env->enemy_y * -1), ft_abs(co[i].x) - ft_abs(env->enemy_x * -1));        
        if (ft_abs(ft_abs(env->enemy_x) - ft_abs(co[i].x)) < distance_x)
        {
            if (ft_abs(ft_abs(env->enemy_y) - ft_abs(co[i].y)) < distance_y)
            {
                distance_y = ft_abs(env->enemy_y) - ft_abs(co[i].y);
                distance_x = ft_abs(env->enemy_x) - ft_abs(co[i].x);
                ft_abs(distance_x);
                ft_abs(distance_y);
                name = i;
            }
        }
        i++;      
    }
    dprintf(env->fd, "name = %d\n", name);
    if (name == -1)
        return (-1);
    env->player_x = co[name].x;
    env->player_y = co[name].y;
    return (0);
}

int       best_choice_two(t_filler *env, t_co *co, int nb)
{
    int i;
    int distance_x;
    int distance_y;
    int name;

    distance_x = 0;
    distance_y = 0;
    i = 0;
    name = -1;
    while (i < nb)
    {
        dprintf(env->fd, "i = %d co[i].x = %d, co[i].y = %d, enemy_x = %d, enemy_y = %d, distance_x = %d, distance_y = %d r_y = %d, r_x = %d\n\n",
         i, co[i].x,co[i].y, env->enemy_x, env->enemy_y, ft_abs(distance_x), ft_abs(distance_y), ft_abs(co[i].y) - ft_abs(env->enemy_y * -1), ft_abs(co[i].x) - ft_abs(env->enemy_x * -1));        
        if (ft_abs(ft_abs(env->enemy_x) + ft_abs(co[i].x)) > distance_x)
        {
            if (ft_abs(ft_abs(env->enemy_y) + ft_abs(co[i].y)) > distance_y)
            {
                distance_y = ft_abs(env->enemy_y) / ft_abs(co[i].y);
                distance_x = ft_abs(env->enemy_x) / ft_abs(co[i].x);
                ft_abs(distance_x);
                ft_abs(distance_y);
                name = i;
                i = 0;
            }
        }
        i++;      
    }
    dprintf(env->fd, "name = %d\n", name);
    if (name == -1)
        return (-1);
    env->player_x = co[name].x;
    env->player_y = co[name].y;
    return (0);
}

int         last_line(t_filler *env, t_map *map)
{
    int y;
    int x;

    y = 0;
    x = 0;
        while (y < env->length_map_y)
        {
            if (map->map_two[env->length_map_x][y] == env->player)
            {
                x++;
            }
            y++;
        }
        if (x > 3)
            return (0);
        return (-1);
}

int         best_choice_x(t_filler *env, t_co *co, int nb)
{
    int i;
    int distance_x;
    int distance_y;
    int name;

    distance_x = 100;
    distance_y = 100;
    i = 0;
    name = -1;
    while (i < nb)
    {
        dprintf(env->fd, "i = %d co[i].x = %d, co[i].y = %d, enemy_x = %d, enemy_y = %d, distance_x = %d, distance_y = %d r_y = %d, r_x = %d\n\n",
         i, co[i].x,co[i].y, env->enemy_x, env->enemy_y, ft_abs(distance_x), ft_abs(distance_y), ft_abs(co[i].y) - ft_abs(env->enemy_y * -1), ft_abs(co[i].x) - ft_abs(env->enemy_x * -1));        
        if (ft_abs(ft_abs(env->enemy_x) - ft_abs(co[i].x)) < distance_x)
        {
            if (ft_abs(ft_abs(env->enemy_y) - ft_abs(co[i].y)) < distance_y)
            {
                distance_y = ft_abs(env->enemy_y) - ft_abs(co[i].y);
                distance_x = ft_abs(env->enemy_x) - ft_abs(co[i].x);
                ft_abs(distance_x);
                ft_abs(distance_y);
                name = i;
                i = 0;
            }
        }
        i++;      
    }
    dprintf(env->fd, "name = %d\n", name);
    if (name == -1)
        return (-1);
    env->player_x = co[name].x;
    env->player_y = co[name].y;
    return (0);
}

int        solveur(t_filler *env, t_map *map)
{
    int x;
    int y;
    int i;
    t_co *co;

    x = 0 ;
    i = 0;
    y = 0 ;
    env->j = 0;
    co = (t_co*)ft_memalloc(sizeof(t_co) * 10000);
    count_star(env, map);
    while (x < env->length_map_x)
    {
        y = 0 - env->length_parts_y;
        while (y < env->length_map_y)
        {
            if (check_pisition(env, map, x, y) == 0)
            {
                dprintf(env->fd,"||%c||\n\n\n",map->tmp_one[x][y]);
                dprintf(env->fd, "COORD: %d  %d\n\n\n\n", x, y);
                dprintf(env->fd, "%d\n\n\n", env->length_map_y);
                co[i].x = x;
                co[i].y = y;
                i++;
            }
            y++;
        }
        x++;
    }
    x = 0;
    int test= 0;
    while (test < i)
    {
        dprintf(env->fd, "co[%d].x = %d, co[%d].y = %d , i = %d\n\n", test, co[test].x,test ,co[test].y ,i);
        test++;
    }
    if (env->pr == 0)
    {
         while (x < env->length_map_x)
        {
            y = 0;
            while (y < env->length_map_y)
            {
                map->tmp_two[x][y] = map->map_two[x][y];
                y++;
            }
            x++;
        }
    }
    else
    {
        two_map_comp(env, map);
        while (x < env->length_map_x)
        {
            y = 0;
            while (y < env->length_map_y)
            {
                map->tmp_two[x][y] = map->map_two[x][y];
                y++;
            }
            x++;
        }
    }
    if (last_line(env, map) == 0 && env->length_map_x > 15 && env->player != 'X')
    {
        if (best_choice_two(env, co, i) == -1)
            return (-1);
    }
    else if (best_choice(env, co, i) == -1 && env->player != 'X')
        return (-1);
    else if (env->player == 'X')
    {
        if (best_choice_x(env, co, i) == -1)
            return (-1);
    }
    // while (test < i)
    // {
    //     dprintf(env->fd, "co[%d].x = %d, co[%d].y = %d , i = %d\n\n", test, co[test].x,test ,co[test].y ,i);
    //     test++;
    // }
    free(co);
    return (0);
}



void    parse_map_one(t_filler *env, t_map *map)
{
    int x;
    int y;

    x = 0;
    y = 0;
    while (x < env->length_map_x)
    {
        y = 0;
        while (y < env->length_map_y)
        {
            if(map->map_two[x][y] == 'O')
            {
                env->player_x = x;
                env->player_y = y;
                env->distance = 0;
            }
            else if (map->map_two[x][y] == 'X')
            {
                // env->enemy_x = x;
                // env->enemy_y = y;
                dprintf(env->fd, "|ft_parse_map_one| player_x = {%d} player_y = {%d} enemy_x = {%d} enemy_y = {%d} distance = {%d} \n",
    env->player_x, env->player_y, env->enemy_x, env->enemy_y, env->distance);
                return;
            }
            env->distance++;
            y++;
        }
        x++;
    }
}

void    ft_bzero_double(t_map *map, int n, int m)
{
    int i;

    i = 0;
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
    // while (i < 100)
    // {
    //     while (k < 99)
    //     {
    //         map->parts[i][k] = '\0';
    //         k++;
    //     }
    //     i++;
    // }
    // k = 0;
    // i = 0;
    while (i <= env->length_parts_y)
    {
        map->parts[env->j][k] = str[i];
        i++;
        k++;
    }
    dprintf(env->fd, "%d|%s|\n", env->j, map->parts[env->j]);
}

void    filling_map_zero(char *str, t_filler *env, t_map *map)
{
    int i;
    int k;

    i = 4;
    k = 0;
    while (i <= 21)
    {
        map->map_two[env->i][k] = str[i];
        i++;
        k++;
    }
//    //dprintf(env->fd, "%d|%s|\n", env->j, map->map_two[env->j]);
}

void    filling_map_one(char *str, t_filler *env,  t_map *map)
{
    int i;
    int k;

    i = 4;
    k = 0;
    while (i <= 44)
    {
        map->map_two[env->i][k] = str[i];
        i++;
        k++;
    }
    dprintf(env->fd, "++%d|%s|++\n", env->i, map->map_two[env->i]);
}
void    filling_map_two(char *str, t_filler *env,  t_map *map)
{
    int i;
    int k;

    i = 4;
    k = 0;
    while (i <= 103)
    {
        map->map_two[env->i][k] = str[i];
        i++;
        k++;
    }
    dprintf(env->fd, "%d|%s|\n", env->i, map->map_two[env->i]);
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
    while (ft_isdigit(str[i]) != 1 && str[i] != '\0')
        i++;
    env->length_parts_x = ft_atoi(&str[i]);
    i = i + 2;
    while (ft_isdigit(str[i]) != 1 && str[i] != '\0')
        i++;
    env->length_parts_y = ft_atoi(&str[i]);
    dprintf(env->fd, "|length of the parts|length_parts_x = {%d} length_parts_y = {%d}\n", env->length_parts_x, env->length_parts_y);
}

void length_of_the_map(char *str, t_filler *env)
{
    int i;

    i = 0;
    while (ft_isdigit(str[i]) != 1 && str[i] != '\0')
        i++;
    env->length_map_x = ft_atoi(&str[i]);
    i = i + 3;
    while (ft_isdigit(str[i]) != 1 && str[i] != '\0')
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
    int i;

    ft_bzero(&env, sizeof(t_filler));  
	ft_bzero(&map, sizeof(t_map));
    env.fd = open("ttt", O_RDWR | O_APPEND | O_TRUNC);
    str = NULL;
    i = 0;
    while (69)
    {
        if (i == 0)
        {
            get_next_line(0, &str);
            env.player = which_player(str);
            if (which_player(str) == 1)
            {
                env.player = 'O';
                env.enemy = 'X';
            }
            else
            {
                env.player = 'X';
                env.enemy = 'O';
            }
            i++;
        }
        if (i == 1)
        {
            get_next_line(0, &str);
            length_of_the_map(str, &env);
            i++;
        }
        else if (env.length_map_x != 0 && env.i == 0)
        {
            env.i = 0;
            get_next_line(0, &str);
            while (env.i < env.length_map_x)
            {
                get_next_line(0, &str);
                init_map_and_filling(str, &env, &map);
                env.i++;
            }
            get_next_line(0, &str);
        }
        else if (ft_strncmp("Piece", str, 5) == 0)
        {
            env.j = 0; 
            length_of_the_parts(str, &env);
            while (env.j < env.length_parts_x)
            {
                get_next_line(0, &str);                
                init_parts_and_filling(str, &env, &map);
                env.j++;
            }
            
            i = 1;
            env.i = 0;
            if (solveur(&env, &map) == -1)
            {
                ft_putnbr_fd(env.player_x, 1);
                ft_putchar_fd(' ', 1);
                ft_putnbr_fd(env.player_y, 1);
                ft_putchar_fd('\n', 1);
                break;
            }
            first_star(&env, &map);
            ft_putnbr_fd(env.player_x, 1);
            ft_putchar_fd(' ', 1);
            ft_putnbr_fd(env.player_y, 1);
            ft_putchar_fd('\n', 1);
            env.pr++;            
        }
    }
    close(env.fd);
    return (0);
}
