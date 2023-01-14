/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelabid <aelabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 18:33:24 by aelabid           #+#    #+#             */
/*   Updated: 2023/01/14 10:07:20 by aelabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/cub3d.h"

void	init_ray(double ray_angle)
{
	if ((ray_angle < 2 * M_PI) && (ray_angle > M_PI))
		ray.isUp = 1;
	else
		ray.isUp = 0;
	if ((ray_angle < M_PI / 2) || (ray_angle > 3 * (M_PI / 2)))
		ray.isRight = 1;
	else
		ray.isRight = 0;
}

double	norm_angle(double angle)
{
	if (angle >= 0)
		angle = fmod(angle, (2 * M_PI));
	else
		angle += (2 * M_PI);
	return (angle);
}

void	get_first_intersection_h(double ray_angle)
{
	util.first_intersection.y = floor(p.y / REC_SIZE) * REC_SIZE;
	if (!ray.isUp)
		util.first_intersection.y += REC_SIZE;
	util.first_intersection.x = p.x
		+ (util.first_intersection.y - p.y) / tan(ray_angle);
}

void	init_step_h(double ray_angle)
{
	util.step.y = REC_SIZE;
	if (ray.isUp)
		util.step.y *= -1;
	util.step.x = REC_SIZE / tan(ray_angle);
	if (!ray.isRight && util.step.x > 0)
		util.step.x *= -1;
	if (ray.isRight && util.step.x < 0)
		util.step.x *= -1;
}

void	horiz_check(double ray_angle)
{
	get_first_intersection_h(ray_angle);
	init_step_h(ray_angle);
	util.wallH.x = util.first_intersection.x;
	util.wallH.y = util.first_intersection.y;
	if (ray.isUp)
		util.wallH.y--;
	while (util.wallH.x <= win.win_w && util.wallH.x >= 0
		&& util.wallH.y <= win.win_h && util.wallH.y >= 0)
	{
		if (is_wall(util.wallH.x, util.wallH.y))
			break ;
		else
		{
			util.wallH.x += util.step.x;
			util.wallH.y += util.step.y;
		}
	}
}
