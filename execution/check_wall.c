/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelabid <aelabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 18:11:14 by aelabid           #+#    #+#             */
/*   Updated: 2023/01/13 01:03:31 by aelabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/cub3d.h"

int	is_wall(double x, double y)
{
	int	nx;
	int	ny;

	nx = floor(x / REC_SIZE);
	ny = floor(y / REC_SIZE);
	if (nx >= win.nb_col)
		nx = win.nb_col - 1;
	if (ny >= win.nb_row)
		ny = win.nb_row - 1;
	return (matrix[ny][nx] != '0');
}
