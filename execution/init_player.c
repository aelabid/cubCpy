/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelabid <aelabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 15:53:09 by aelabid           #+#    #+#             */
/*   Updated: 2023/01/14 08:10:44 by aelabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/cub3d.h"

void	get_angle(t_map *map)
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

void	init_player(t_map *map)
{
	p.x = (map->x * 32);
	p.y = (map->y * 32);
	p.turn_dir = 0;
	p.walk_dir = 0;
	get_angle(map);
	p.move_speed = 2;
	p.rotat_speed = 5 * (M_PI / 180);
	p.size = 11;
}

void	move_player(void)
{
	int		steps;
	double	tempx;
	double	tempy;

	steps = p.walk_dir * p.move_speed;
	tempx = p.x + cos(p.rotate_angle) * steps;
	tempy = p.y + sin(p.rotate_angle) * steps;
	if (!is_wall(tempx, tempy))
	{
		p.x = tempx;
		p.y = tempy;
	}
}

void	move_sides(void)
{
	int		steps;
	double	tempx;
	double	tempy;

	steps = p.walk_dir * p.move_speed;
	tempx = p.x + cos(p.rotate_angle - (M_PI / 2)) * steps ;
	tempy = p.y + sin(p.rotate_angle - (M_PI / 2)) * steps ;
	if (!is_wall(tempx, tempy))
	{
		p.x = tempx;
		p.y = tempy;
	}
}

void	render_player(t_data data)
{
	render_lines(data);
}
