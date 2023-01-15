/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelba <mabdelba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 21:59:13 by mabdelba          #+#    #+#             */
/*   Updated: 2023/01/14 22:05:13 by mabdelba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

bool	line_isspace(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			return (false);
		i++;
	}
	return (true);
}

int	exist_player(char *str, int drp)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (str[i])
	{
		if (str[i] == 'S' || str[i] == 'N' || str[i] == 'W' || str[i] == 'E')
		{
			res++;
			if (drp == 1)
				return (i);
			if (drp == 2)
				return (str[i]);
		}
		i++;
	}
	if (drp == 1)
		return (-1);
	return (res);
}

bool	line_iswall(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '0')
			return (false);
		i++;
	}
	return (true);
}

bool	vertical_walls(char *str)
{
	int		i;
	int		j;

	i = 0;
	j = ft_strlen(str) - 1;
	while (str[i])
	{
		if (str[i] == '1')
			break ;
		if (str[i] == '0' || char_isdirection(str[i]))
			return (false);
		i++;
	}
	while (j >= 0)
	{
		if (str[j] == '1')
			break ;
		if (str[j] == '0' || char_isdirection(str[j]))
			return (false);
		j--;
	}
	return (true);
}

void	checkup_holes(char **str, int j)
{
	int	i;

	i = 0;
	if (str[i][j] == ' ')
	{
		i++;
		while (str[i] && str[i][j] != '1')
		{
			if (str[i][j] == '0' || char_isdirection(str[i][j]))
				error_function("Invalid Map: Map is not closed");
			i++;
		}
	}
}
