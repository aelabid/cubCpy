/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelabid <aelabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 15:53:09 by aelabid           #+#    #+#             */
/*   Updated: 2023/01/13 01:04:26 by aelabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/cub3d.h"


void    get_angle(t_map *map)
{
    if (map->dir == 'S')
        p.rotate_angle = (M_PI / 2); 
    else if (map->dir == 'N')
        p.rotate_angle = 3 * (M_PI / 2); 
    else if (map->dir == 'E')
        p.rotate_angle = 2 * M_PI; 
    else if (map->dir == 'W')
        p.rotate_angle = M_PI; 
}
void    init_player(t_map *map)
{
    // printf("p.x = %d p.y = %d\t win width /2 = %d win h /2 = %d\n", (map->x)*32, (map->y)*32, win.win_w / 2, win.win_h / 2);
    // p.x = win.win_w / 2;
    // p.y = win.win_h / 2;
    p.x = (map->x * 32);
    p.y = (map->y * 32);

    p.turn_dir = 0; //left "A" right "D"
    p.walk_dir = 0; //nichan "W" lour "S"
    get_angle(map);
    p.move_speed = 2;
    p.rotat_speed = 5 * (M_PI / 180);
    p.size = 11;
}

void  move_player()
{
    double tempx;
    double tempy;
    int steps;

    steps = p.walk_dir * p.move_speed;
    tempx = p.x + cos(p.rotate_angle) * steps;
    tempy = p.y + sin(p.rotate_angle) * steps;
    if (!is_wall(tempx, tempy)&& !is_wall(tempx + p.size, tempy+p.size))
    {
        p.x = tempx;
        p.y = tempy;
    }
    if (p.x <= 0)
        p.x = 0;
    if (p.y <= 0)
        p.y = 0;
    if (p.x >= win.win_w)
        p.x = win.win_w;
    if (p.y >= win.win_h)
        p.y = win.win_h;
}


void  move_sides()
{
    int steps = p.walk_dir * p.move_speed;
    double tempx;
    double tempy;

    tempx = p.x + cos(p.rotate_angle - (M_PI / 2)) * steps ;
    tempy = p.y + sin(p.rotate_angle - (M_PI / 2)) * steps ;
    if (!is_wall(tempx, tempy) && !is_wall(tempx + p.size, tempy+p.size))
    {
        p.x = tempx;
        p.y = tempy;
    }
    if (p.x <= 0)
        p.x = 0;
    if (p.y <= 0)
        p.y = 0;
    if (p.x >= win.win_w)
        p.x = win.win_w;
    if (p.y >= win.win_h)
        p.y = win.win_h;
}

void  render_player(t_data data)
{
    // render_colored_rect((t_rect){p.x, p.y, p.size, RED_PIXEL});
    render_lines(data);
}