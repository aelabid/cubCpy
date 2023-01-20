/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelabid <aelabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 15:53:09 by aelabid           #+#    #+#             */
/*   Updated: 2023/01/20 19:18:37 by aelabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/cub3d.h"

void	get_angle(t_map *map)
{
	if (map->dir == 'S')
		g_util.p.rotate_angle = (M_PI / 2);
	else if (map->dir == 'N')
		g_util.p.rotate_angle = 3 * (M_PI / 2);
	else if (map->dir == 'E')
		g_util.p.rotate_angle = M_PI;
	else if (map->dir == 'W')
		g_util.p.rotate_angle = 2 * M_PI;
}

void	init_player(t_map *map)
{
	g_util.p.x = (map->x * REC_SIZE + 5);
	g_util.p.y = (map->y * REC_SIZE + 5);
	g_util.p.turn_dir = 0;
	g_util.p.walk_dir = 0;
	get_angle(map);
	g_util.p.move_speed = 2;
	g_util.p.rotat_speed = 5 * (M_PI / 180);
	g_util.p.size = 11;
}

void	move_player(void)
{
	int		steps;
	double	tempx;
	double	tempy;

	steps = g_util.p.walk_dir * g_util.p.move_speed;
	tempx = g_util.p.x + cos(g_util.p.rotate_angle) * steps;
	tempy = g_util.p.y + sin(g_util.p.rotate_angle) * steps;
	if (!is_wall(tempx, tempy))
	{
		g_util.p.x = tempx;
		g_util.p.y = tempy;
	}
}

void	move_sides(void)
{
	int		steps;
	double	tempx;
	double	tempy;

	steps = g_util.p.walk_dir * g_util.p.move_speed;
	tempx = g_util.p.x + cos(g_util.p.rotate_angle - (M_PI / 2)) * steps ;
	tempy = g_util.p.y + sin(g_util.p.rotate_angle - (M_PI / 2)) * steps ;
	if (!is_wall(tempx, tempy))
	{
		g_util.p.x = tempx;
		g_util.p.y = tempy;
	}
}

void	render_player(t_data data)
{
	render_lines(data);
}
