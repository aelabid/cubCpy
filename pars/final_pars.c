/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_pars.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelabid <aelabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 18:30:13 by aelabid           #+#    #+#             */
/*   Updated: 2023/01/18 18:47:01 by aelabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	check_trou(char **str, int i, int j)
{
	if (str[i - 1][j] && str[i - 1][j] == ' ')
		error_function("Invalid Map: Not closed");
	if (str[i + 1][j] && str[i + 1][j] == ' ')
		error_function("Invalid Map: Not closed");
	if (str[i][j - 1] && str[i][j - 1] == ' ')
		error_function("Invalid Map: Not closed");
	if (str[i][j + 1] && str[i][j + 1] == ' ')
		error_function("Invalid Map: Not closed");
}

void	final_pars(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->matrice[i])
	{
		j = 0;
		while (map->matrice[i][j])
		{
			if (map->matrice[i][j] == '0')
				check_trou(map->matrice, i, j);
			j++;
		}
		i++;
	}
}
