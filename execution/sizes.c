/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sizes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelabid <aelabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 21:02:35 by aelabid           #+#    #+#             */
/*   Updated: 2023/01/18 17:39:45 by aelabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/cub3d.h"

void	get_sizes(t_map *map)
{
	g_util.matrice = map->matrice;
	g_util.win.nb_row = ft_spllen(map->matrice);
	g_util.win.nb_col = ft_strlen(map->matrice[0]);
	g_util.win.win_h = 1024;
	g_util.win.win_w = 1024;
}
