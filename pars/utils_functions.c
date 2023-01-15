/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelba <mabdelba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 20:53:21 by mabdelba          #+#    #+#             */
/*   Updated: 2023/01/14 22:00:32 by mabdelba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

char	*c_tos(char c)
{
	char	tab[2];

	tab[0] = c;
	tab[1] = '\0';
	return (ft_strdup(tab));
}

bool	char_isdirection(char c)
{
	if (c == 'E' || c == 'W' || c == 'S' || c == 'N')
		return (true);
	else
		return (false);
}

bool	line_isdigit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '0' && str[i] != '1'
			&& str[i] != '\n' && str[i] != 'E' && str[i] != 'W'
			&& str[i] != 'N' && str[i] != 'S')
			return (false);
		i++;
	}
	return (true);
}
