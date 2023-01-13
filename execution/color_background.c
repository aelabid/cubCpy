/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_background.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelabid <aelabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 00:00:21 by aelabid           #+#    #+#             */
/*   Updated: 2023/01/13 01:08:48 by aelabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/cub3d.h"

void	color_background(t_data data)
{
	int	i;

	i = 0;
	while (i < win.win_h / 2)
	{
		DDA(0, i, win.win_w, i, convert_color(data.c));
		i++;
	}
	while (i < win.win_h)
	{
		DDA(0, i, win.win_w, i, convert_color(data.f));
		i++;
	}
}
