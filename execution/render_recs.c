/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_recs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelabid <aelabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 12:25:22 by aelabid           #+#    #+#             */
/*   Updated: 2023/01/13 01:05:45 by aelabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/cub3d.h"



int render_wall(t_wall wall)
{
	double	i;

	if (mlx.win_ptr == NULL)
		return (1);
	i = wall.y;
	int *color = right_text.addr;
	int	x_textur ;
	float h;
	double distance_from_top;
	if(ray.is_horizontal)
	{	
		h = c_wall.x / REC_SIZE;
	}
	else
	{
		h = c_wall.y / REC_SIZE;
	}
		x_textur = (h - (int)h) * right_text.width;
	int y_textur;
	while (i < wall.y + wall.height)
	{
		y_textur = (i - wall.y) * ((double)right_text.height / wall.height);
		my_mlx_pixel_put(wall.x, i, color[(right_text.width * y_textur) + x_textur]); 
		++i;
	}
	return (0);
}
