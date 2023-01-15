/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelba <mabdelba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 22:18:40 by mabdelba          #+#    #+#             */
/*   Updated: 2023/01/14 22:19:50 by mabdelba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	error_function(char *str)
{
	printf("Error\n=> %s!\n", str);
	exit(1);
}

int	openfile(char *str)
{
	int	fd;

	fd = open(str, O_RDONLY);
	if (fd < 0)
		error_function("file is not found");
	return (fd);
}

bool	str_direction(char *str)
{
	if (!ft_strncmp(str, "WE", ft_strlen(str))
		|| !ft_strncmp(str, "EA", ft_strlen(str))
		|| !ft_strncmp(str, "NO", ft_strlen(str))
		|| !ft_strncmp(str, "SO", ft_strlen(str)))
		return (true);
	else
		return (false);
}

bool	str_color(char *str)
{
	if (!ft_strncmp(str, "F", ft_strlen(str))
		|| !ft_strncmp(str, "C", ft_strlen(str)))
		return (true);
	else
		return (false);
}

bool	sdigit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (false);
		i++;
	}
	return (true);
}
