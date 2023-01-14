/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_windows.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelabid <aelabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 07:14:34 by aelabid           #+#    #+#             */
/*   Updated: 2023/01/14 08:14:33 by aelabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/cub3d.h"

void	open_window(void)
{
	mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, win.win_w, win.win_h, "CUB3D");
	mlx.img = NULL;
}
