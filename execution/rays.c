/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelabid <aelabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 18:33:24 by aelabid           #+#    #+#             */
/*   Updated: 2023/01/13 01:04:57 by aelabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/cub3d.h"

// t_point    render_center_of_player()
// {
//     t_point center;

//     center.x =  p.x ;
//     center.y =  p.y ;
//     my_mlx_pixel_put(center.x, center.y, RED_PIXEL);
//     return (center);
// }
t_point	first_intersection_h;
t_point	first_intersection_v;
t_point	stepH;
t_point	stepV;
t_point	wallH;
t_point	wallV;

void    init_ray(double ray_angle)
{
	ray.isDown = ray_angle > 0 && ray_angle < M_PI;
	ray.isUp = !ray.isDown;
	ray.isRight = (ray_angle < M_PI / 2) || (ray_angle > 3 * (M_PI / 2)); 
	ray.isLeft = !ray.isRight;
}


double  norm_angle(double angle)
{
	if (angle >= 0)
		angle = fmod(angle, (2 * M_PI));
	else
		angle += (2 * M_PI);
		return(angle);
}

// ---------------Horizontal check -----------------//
void    get_first_intersection_h(double ray_angle)
{
	first_intersection_h.y = floor(p.y / REC_SIZE) * REC_SIZE;
	if (!ray.isUp)
		first_intersection_h.y += REC_SIZE;
	first_intersection_h.x = p.x + (first_intersection_h.y - p.y) / tan(ray_angle);
}
void    init_step_H(double ray_angle)
{
	stepH.y = REC_SIZE;
	stepH.y *= ray.isUp ? -1 : 1;

	stepH.x = REC_SIZE / tan(ray_angle);
	stepH.x *= (!ray.isRight && stepH.x > 0) ? -1 : 1;
	stepH.x *= (ray.isRight && stepH.x < 0) ? -1 : 1;
}

void    horiz_check(double ray_angle)
{
	get_first_intersection_h(ray_angle);
	init_step_H(ray_angle);
	wallH.x = first_intersection_h.x;
	wallH.y = first_intersection_h.y;
	if (ray.isUp)
		wallH.y--;
	// printf("win h = %d wall.y = %f win w = %d\n", win.win_h, wallH.y, win.win_w);
	int i =0;
	// printf("x = %f y = %f\n", wallH.x, wallH.y);
	while(wallH.x <= win.win_w && wallH.x >=0 && wallH.y <= win.win_h && wallH.y >=0)
	{
		if(is_wall(wallH.x, wallH.y))
			break;
		else
		{
			wallH.x += stepH.x;
			wallH.y += stepH.y;
		}
	}
}
// ---------------Vertical check -----------------//

void    get_first_intersection_v(double ray_angle)
{
	first_intersection_v.x = floor(p.x / REC_SIZE) * REC_SIZE;
	if (ray.isRight)
		first_intersection_v.x += REC_SIZE;
	first_intersection_v.y = p.y + (first_intersection_v.x - p.x) * tan(ray_angle);
}

void    init_step_V(double ray_angle)
{
	stepV.x = REC_SIZE;
	stepV.x *= !ray.isRight ? -1 : 1;

	stepV.y = REC_SIZE * tan(ray_angle);
	stepV.y *= (ray.isUp && stepV.y > 0) ? -1 : 1;
	stepV.y *= (!ray.isUp && stepV.y < 0) ? -1 : 1;
}

void    vertical_check(double ray_angle)
{
	get_first_intersection_v(ray_angle);
	init_step_V(ray_angle);
	wallV.x = first_intersection_v.x;
	wallV.y = first_intersection_v.y;
	if (!ray.isRight)
		wallV.x--;
	int i =0;
	while(wallV.x <= win.win_w && wallV.x >=0 && wallV.y <= win.win_h && wallV.y >=0)
	{
		if(is_wall(wallV.x, wallV.y))
			break;
		else
		{
			// render_empty_rect((t_rect){wallV.x, wallV.y, 10, RED_PIXEL});
			wallV.x += stepV.x;
			wallV.y += stepV.y;
		}
	}
}

double  get_distance(double x, double y)
{
	double  dis;
	double  x0;
	double  y0;

	x0 = p.x + p.size / 2;
	y0 = p.y + p.size / 2;
	dis = sqrt((x - x0) * (x - x0) + (y - y0) * (y - y0));
	return (dis);
}

void    get_closest_wall(double ray_angle)
{
	double distance_h;
	double distance_v;
	vertical_check(ray_angle);
	horiz_check(ray_angle);
	distance_h = get_distance(wallH.x, wallH.y);
	distance_v = get_distance(wallV.x, wallV.y);
	if (distance_h < distance_v )
	{
		c_wall.x = wallH.x;
		c_wall.y = wallH.y;
		ray.is_horizontal = 1;
	}
	else
	{
		c_wall.x = wallV.x;
		c_wall.y = wallV.y;
		ray.is_horizontal = 0;
	}
	if ((int) wallV.y == (int) wallH.y)
	{
		c_wall.x = wallH.x;
		c_wall.y = wallH.y;
		ray.is_horizontal = 1;
	}
	else if ((int) wallV.x == (int) wallH.x)
	{
		ray.is_horizontal = 0;
		c_wall.x = wallV.x;
		c_wall.y = wallV.y;
	}
	ray.distance = get_distance(c_wall.x, c_wall.y);
}

void    get_finale_distance(double ray_angle)
{
	ray.finale_distance = ray.distance * cos(ray_angle - p.rotate_angle);
}

void    projected(int i)
{
	double  distance_to_window = (win.win_w / 2) / tan(info.fov / 2);
	double  wall_projected_height = REC_SIZE / ray.finale_distance * distance_to_window;

	render_wall((t_wall){i, (win.win_h / 2) - ((int)wall_projected_height / 2), wall_projected_height,info.ray_strip});
}

t_texture	get_right_wall(double  ray_angle)
{
	if (ray.is_horizontal)
	{
		if((ray_angle <= (2 * M_PI) && ray_angle >= M_PI))
			return (texture[1]);
		else
			return (texture[0]);
	}
	else
	{
		if((ray_angle <= 3 * M_PI / 2 && ray_angle >= M_PI/2))
			return (texture[3]);
		else
			return (texture[2]);

	}
}
void    render_lines(t_data data)
{
	double  ray_angle;
	int     i;

	i = 1;
	ray_angle = (p.rotate_angle - (info.fov / 2));
	get_images(data);
	while (i < info.num_ray)
	{
		ray_angle = norm_angle(ray_angle);
		init_ray(ray_angle);
		get_closest_wall(ray_angle);
		get_finale_distance(ray_angle);
		right_text = get_right_wall(ray_angle);
	//  DDA((p.x + p.size / 2), (p.y + p.size /2), c_wall.x, c_wall.y, RED_PIXEL);
		projected(i);
		i++;
		ray_angle += (info.fov / info.num_ray); 
	}
}

