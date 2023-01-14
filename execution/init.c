/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelabid <aelabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 16:16:24 by aelabid           #+#    #+#             */
/*   Updated: 2023/01/14 08:13:24 by aelabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/cub3d.h"

void	init_info(void)
{
	info.fov = 60 * (M_PI / 180);
	info.ray_strip = 1;
	info.num_ray = win.win_w / info.ray_strip;
}
