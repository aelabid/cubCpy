/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelba <mabdelba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 22:56:22 by mabdelba          #+#    #+#             */
/*   Updated: 2023/01/14 21:58:52 by mabdelba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	checkdown_holes(char **str, int j)
{
	int	i;

	i = ft_spllen(str) - 1;
	if (str[i][j] == ' ')
	{
		i--;
		while (i >= 0 && str[i][j] != '1')
		{
			if (str[i][j] == '0' || char_isdirection(str[i][j]))
				error_function("Invalid Map: Map is not closed");
			i--;
		}
	}
}

void	check_holes(t_map *map)
{
	int	len;
	int	i;

	len = ft_strlen(map->matrice[0]);
	i = 0;
	while (i < len)
	{
		checkup_holes(map->matrice, i);
		checkdown_holes(map->matrice, i);
		i++;
	}
}

void	check_walls(t_map *map)
{
	int	last;
	int	i;

	i = 0;
	last = ft_spllen(map->matrice) - 1;
	if (!line_iswall(map->matrice[0]) || !line_iswall(map->matrice[last])
		|| exist_player(map->matrice[0], 0)
		|| exist_player(map->matrice[last], 0))
		error_function("Invalid Map: walls");
	while (map->matrice[i])
	{
		if (!vertical_walls(map->matrice[i]))
			error_function("Invalid Map: walls");
		if (map->matrice[i + 1] && line_isspace(map->matrice[i]))
		{
			if (!line_isspace(map->matrice[i + 1])
				&& !line_iswall(map->matrice[i + 1]))
				error_function("Invalid Map");
		}
		i++;
	}
}

void	change_player(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (char_isdirection(str[i]))
		{
			str[i] = '0';
			break ;
		}
		i++;
	}
}

void	check_map(t_map *map)
{
	int	i;
	int	flg;

	i = 0;
	flg = 0;
	while (map->matrice[i])
	{
		flg += exist_player(map->matrice[i], 0);
		if (!line_isdigit(map->matrice[i]) || flg > 1)
			error_function("Invalid Map");
		if (exist_player(map->matrice[i], 0)
			&& exist_player(map->matrice[i], 1) != -1)
		{
			map->y = i;
			map->x = exist_player(map->matrice[i], 1);
			map->dir = (char)exist_player(map->matrice[i], 2);
			change_player(map->matrice[i]);
		}
		i++;
	}
	if (flg == 0)
		error_function("Invalid Map: No player");
	check_walls(map);
	check_holes(map);
}
