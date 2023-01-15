/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_uts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelba <mabdelba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 22:29:37 by mabdelba          #+#    #+#             */
/*   Updated: 2023/01/14 22:35:26 by mabdelba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	check_color(char *str)
{
	char	**spl;
	int		i;

	spl = ft_split(str, ',');
	if (ft_spllen(spl) != 3)
		error_function("Invalid Map: \"Colors\"");
	i = 0;
	while (i < 3)
	{
		if (!sdigit(spl[i]))
			error_function("Invalid Map: \"Colors\"");
		if (ft_atoi(spl[i]) < 0 || ft_atoi(spl[i]) > 255)
			error_function("Invalid Map: \"Colors\"");
		i++;
	}
	ft_free(spl);
}

void	collect_texture(t_data *data, char *dir, char *path)
{
	if (!str_color(dir))
		openfile(path);
	if (!ft_strncmp(dir, "NO", ft_strlen(dir)))
		data->no = ft_strdup(path);
	else if (!ft_strncmp(dir, "SO", ft_strlen(dir)))
		data->so = ft_strdup(path);
	else if (!ft_strncmp(dir, "WE", ft_strlen(dir)))
		data->we = ft_strdup(path);
	else if (!ft_strncmp(dir, "EA", ft_strlen(dir)))
		data->ea = ft_strdup(path);
	else if (!ft_strncmp(dir, "F", ft_strlen(dir)))
	{
		check_color(path);
		data->f = ft_strdup(path);
	}
	else if (!ft_strncmp(dir, "C", ft_strlen(dir)))
	{
		check_color(path);
		data->c = ft_strdup(path);
	}
}

void	collect_map(t_map *map, int fd, t_size size, char *str)
{
	int	i;
	int	j;

	map->matrice = malloc((size.maplines + 1) * sizeof(char *));
	i = 0;
	while (str)
	{
		if (str[ft_strlen(str) - 1] != '\n')
			str = ft_strcat(str, "\n");
		map->matrice[i] = malloc((size.longest) * sizeof(char));
		if (!map->matrice[i])
			error_function("Allocation problem");
		map->matrice[i] = ft_strcpy(map->matrice[i], str);
		j = ft_strlen(str) - 1;
		while (j < size.longest - 1)
		{
			map->matrice[i][j] = ' ';
			j++;
		}
		map->matrice[i][j] = '\0';
		free(str);
		str = get_next_line(fd);
		i++;
	}
	map->matrice[i] = NULL;
}
