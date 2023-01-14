/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelabid <aelabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 16:16:24 by aelabid           #+#    #+#             */
/*   Updated: 2023/01/14 11:23:04 by aelabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/cub3d.h"

void	init_info(void)
{
	g_util.info.fov = 60 * (M_PI / 180);
	g_util.info.ray_strip = 1;
	g_util.info.num_ray = g_util.win.win_w / g_util.info.ray_strip;
}
