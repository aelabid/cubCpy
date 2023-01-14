/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelabid <aelabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 12:29:05 by aelabid           #+#    #+#             */
/*   Updated: 2023/01/14 08:06:55 by aelabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/cub3d.h"

void	check_more_key(t_data data)
{
	if (key_press.right)
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
}

void	check_key(t_data data)
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
}

int	handle_keypress(t_data *data)
{
	check_key(*data);
	check_more_key(*data);
	render_image(*data);
	return (0);
}
