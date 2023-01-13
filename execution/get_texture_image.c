/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture_image.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelabid <aelabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 13:27:32 by aelabid           #+#    #+#             */
/*   Updated: 2023/01/13 01:06:17 by aelabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/cub3d.h"

void    get_images(t_data data)
{
    texture[0].img = mlx_xpm_file_to_image(mlx.mlx_ptr, data.no, &texture[0].width, &texture[0].height);
    texture[0].addr = (int *)mlx_get_data_addr(texture[0].img, &texture[0].bits_per_pixel, &texture[0].line_length,
								&texture[0].endian);
    texture[1].img = mlx_xpm_file_to_image(mlx.mlx_ptr, data.so, &texture[1].width, &texture[1].height);
    texture[1].addr = (int *)mlx_get_data_addr(texture[1].img, &texture[1].bits_per_pixel, &texture[1].line_length,
								&texture[1].endian);
    texture[2].img = mlx_xpm_file_to_image(mlx.mlx_ptr, data.ea, &texture[2].width, &texture[2].height);
    texture[2].addr = (int *)mlx_get_data_addr(texture[2].img, &texture[2].bits_per_pixel, &texture[2].line_length,
								&texture[2].endian);
    texture[3].img = mlx_xpm_file_to_image(mlx.mlx_ptr, data.we, &texture[3].width, &texture[3].height);
    texture[3].addr = (int *)mlx_get_data_addr(texture[3].img, &texture[3].bits_per_pixel, &texture[3].line_length,
								&texture[3].endian);
}