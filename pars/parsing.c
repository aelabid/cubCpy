/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelba <mabdelba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:43:17 by mabdelba          #+#    #+#             */
/*   Updated: 2023/01/14 23:18:01 by mabdelba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	check_spl(char **spl, t_data *data, int *drp)
{
	if (ft_spllen(spl))
	{
		if (ft_spllen(spl) != 2 || (!str_direction(spl[0])
				&& !str_color(spl[0])))
			error_function("Invalide Map");
		if (!check_extension(spl[1], "xpm") && !str_color(spl[0]))
			error_function("Invalid extension \".xpm\" in the Map");
		collect_texture(data, spl[0], spl[1]);
		(*drp)++;
	}
}

void	check_textures(int fd, int fd2, t_data *data, t_map *map)
{
	char	*str;
	char	**spl;
	int		i;
	int		drp;
	t_size	size;

	size = ft_textsize(fd2);
	str = get_next_line(fd);
	i = 0;
	drp = 0;
	while (i < size.textlines)
	{
		spl = ft_spl(str, ' ');
		check_spl(spl, data, &drp);
		i++;
		ft_free(spl);
		free(str);
		str = get_next_line(fd);
	}
	if (drp != 6)
		error_function("Invalid texture");
	collect_map(map, fd, size, str);
}

void	parsing(int ac, char **av, t_data *data, t_map *map)
{
	int	fd;
	int	fd2;

	if (ac != 2)
		error_function("Invalid number of arguments");
	fd = openfile(av[1]);
	fd2 = openfile(av[1]);
	if (!check_extension(av[1], "cub"))
		error_function("Invalid extension: \".cub\"");
	check_textures(fd, fd2, data, map);
	check_map(map);
	close(fd);
	close(fd2);
}
