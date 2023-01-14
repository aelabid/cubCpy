/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelabid <aelabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 10:06:30 by aelabid           #+#    #+#             */
/*   Updated: 2023/01/14 10:11:32 by aelabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/cub3d.h"

void	get_first_intersection_v(double ray_angle)
{
	util.first_intersection.x = floor(p.x / REC_SIZE) * REC_SIZE;
	if (ray.isRight)
		util.first_intersection.x += REC_SIZE;
	util.first_intersection.y = p.y + (util.first_intersection.x - p.x)
		* tan(ray_angle);
}

void	init_step_v(double ray_angle)
{
	util.step.x = REC_SIZE;
	if (!ray.isRight)
		util.step.x *= -1;
	util.step.y = REC_SIZE * tan(ray_angle);
	if (ray.isUp && util.step.y > 0)
		util.step.y *= -1;
	if (!ray.isUp && util.step.y < 0)
		util.step.y *= -1;
}

void	vertical_check(double ray_angle)
{
	get_first_intersection_v(ray_angle);
	init_step_v(ray_angle);
	util.wallV.x = util.first_intersection.x;
	util.wallV.y = util.first_intersection.y;
	if (!ray.isRight)
		util.wallV.x--;
	while (util.wallV.x <= win.win_w && util.wallV.x >= 0
		&& util.wallV.y <= win.win_h && util.wallV.y >= 0)
	{
		if (is_wall(util.wallV.x, util.wallV.y))
			break ;
		else
		{
			util.wallV.x += util.step.x;
			util.wallV.y += util.step.y;
		}
	}
}

double	get_distance(double x, double y)
{
	double	dis;
	double	x0;
	double	y0;

	x0 = p.x + p.size / 2;
	y0 = p.y + p.size / 2;
	dis = sqrt((x - x0) * (x - x0) + (y - y0) * (y - y0));
	return (dis);
}

void	get_wall_util(double distance_h, double distance_v)
{
	if (distance_h < distance_v)
	{
		c_wall.x = util.wallH.x;
		c_wall.y = util.wallH.y;
		ray.is_horizontal = 1;
	}
	else
	{
		c_wall.x = util.wallV.x;
		c_wall.y = util.wallV.y;
		ray.is_horizontal = 0;
	}
}
