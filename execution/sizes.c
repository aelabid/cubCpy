/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sizes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelabid <aelabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 21:02:35 by aelabid           #+#    #+#             */
/*   Updated: 2023/01/13 01:01:35 by aelabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/cub3d.h"

void    get_sizes(t_map  *map)
{
    matrix = map->matrice;
    win.nb_row = ft_spllen(map->matrice);
    win.nb_col = ft_strlen(map->matrice[0]);
    win.win_h = win.nb_row * REC_SIZE;
	win.win_w = win.nb_col * REC_SIZE;
}