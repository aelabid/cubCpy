/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_util2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelabid <aelabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 10:10:47 by aelabid           #+#    #+#             */
/*   Updated: 2023/01/14 10:12:40 by aelabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/cub3d.h"

void	get_closest_wall(double ray_angle)
{
	double	distance_h;
	double	distance_v;

	vertical_check(ray_angle);
	horiz_check(ray_angle);
	distance_h = get_distance(util.wallH.x, util.wallH.y);
	distance_v = get_distance(util.wallV.x, util.wallV.y);
	get_wall_util(distance_h, distance_v);
	if ((int) util.wallV.y == (int) util.wallH.y)
	{
		c_wall.x = util.wallH.x;
		c_wall.y = util.wallH.y;
		ray.is_horizontal = 1;
	}
	else if ((int) util.wallV.x == (int) util.wallH.x)
	{
		ray.is_horizontal = 0;
		c_wall.x = util.wallV.x;
		c_wall.y = util.wallV.y;
	}
	ray.distance = get_distance(c_wall.x, c_wall.y);
}

void	projected(int i)
{
	double	distance_to_window;
	double	wall_projected_height;

	distance_to_window = (win.win_w / 2) / tan(info.fov / 2);
	wall_projected_height = REC_SIZE / ray.finale_distance * distance_to_window;
	render_wall((t_wall){i, (win.win_h / 2)
		- ((int)wall_projected_height / 2),
		wall_projected_height, info.ray_strip});
}

t_texture	get_right_wall(double ray_angle)
{
	if (ray.is_horizontal)
	{
		if ((ray_angle <= (2 * M_PI) && ray_angle >= M_PI))
			return (texture[1]);
		else
			return (texture[0]);
	}
	else
	{
		if ((ray_angle <= 3 * M_PI / 2 && ray_angle >= M_PI / 2))
			return (texture[3]);
		else
			return (texture[2]);
	}
}

void	render_lines(t_data data)
{
	double	ray_angle;
	int		i;

	i = 1;
	ray_angle = (p.rotate_angle - (info.fov / 2));
	get_images(data);
	while (i < info.num_ray)
	{
		ray_angle = norm_angle(ray_angle);
		init_ray(ray_angle);
		get_closest_wall(ray_angle);
		ray.finale_distance = ray.distance * cos(ray_angle - p.rotate_angle);
		right_text = get_right_wall(ray_angle);
		projected(i);
		i++;
		ray_angle += (info.fov / info.num_ray);
	}
}
