/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture_image.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelabid <aelabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 13:27:32 by aelabid           #+#    #+#             */
/*   Updated: 2023/01/20 19:37:49 by aelabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/cub3d.h"

void	image_check(void)
{
	if (!g_util.texture[0].img
		|| !g_util.texture[1].img
		|| !g_util.texture[2].img
		|| !g_util.texture[3].img)
		error_function("texture error");
}

void	get_images(t_data data)
{
	g_util.texture[0].img = mlx_xpm_file_to_image(g_util.mlx.mlx_ptr, data.no,
			&g_util.texture[0].width, &g_util.texture[0].height);
	g_util.texture[1].img = mlx_xpm_file_to_image(g_util.mlx.mlx_ptr, data.so,
			&g_util.texture[1].width, &g_util.texture[1].height);
	g_util.texture[2].img = mlx_xpm_file_to_image(g_util.mlx.mlx_ptr, data.ea,
			&g_util.texture[2].width, &g_util.texture[2].height);
	g_util.texture[3].img = mlx_xpm_file_to_image(g_util.mlx.mlx_ptr, data.we,
			&g_util.texture[3].width, &g_util.texture[3].height);
	image_check();
	g_util.texture[0].addr = (int *)mlx_get_data_addr(g_util.texture[0].img,
			&g_util.texture[0].bits_per_pixel, &g_util.texture[0].line_length,
			&g_util.texture[0].endian);
	g_util.texture[1].addr = (int *)mlx_get_data_addr(g_util.texture[1].img,
			&g_util.texture[1].bits_per_pixel, &g_util.texture[1].line_length,
			&g_util.texture[1].endian);
	g_util.texture[2].addr = (int *)mlx_get_data_addr(g_util.texture[2].img,
			&g_util.texture[2].bits_per_pixel, &g_util.texture[2].line_length,
			&g_util.texture[2].endian);
	g_util.texture[3].addr = (int *)mlx_get_data_addr(g_util.texture[3].img,
			&g_util.texture[3].bits_per_pixel, &g_util.texture[3].line_length,
			&g_util.texture[3].endian);
}
