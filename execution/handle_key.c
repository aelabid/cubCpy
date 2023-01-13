/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelabid <aelabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 12:29:05 by aelabid           #+#    #+#             */
/*   Updated: 2023/01/13 01:08:02 by aelabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/cub3d.h"

void check_key(t_data data)
{
    if (key_press.w)
	{
		p.walk_dir = 1;
		move_player();
	}
    else if (key_press.s)
	{
		p.walk_dir = -1;
		move_player();
    }
	else if (key_press.d)
	{
		p.walk_dir = -1;
		move_sides();
    }
	else if (key_press.a)
	{
		p.walk_dir = 1;
		move_sides();
	}
	else if (key_press.right)
	{
		p.turn_dir = 1;
		p.rotate_angle += p.turn_dir * p.rotat_speed;
		p.rotate_angle = norm_angle(p.rotate_angle);
	}
	else if (key_press.left)
	{
		p.turn_dir = -1;
		p.rotate_angle += p.turn_dir * p.rotat_speed;
		p.rotate_angle = norm_angle(p.rotate_angle);
	}
	render_image(data);
}

int	handle_keypress(t_data *data)
{
	// if (keysym == 53)
	// {
	// 	mlx_destroy_image(mlx->mlx_ptr, mlx->img);
	// 	mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
	// 	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	// 	mlx->win_ptr = NULL;
	// 	exit(0);
	// } else 
		check_key(*data);
		// printf("here\n");
		
	return (0);
}
