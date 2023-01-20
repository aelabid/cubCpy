/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelabid <aelabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 18:29:08 by mabdelba          #+#    #+#             */
/*   Updated: 2023/01/18 18:47:27 by aelabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <stdbool.h>
# include <mlx.h>
# include <fcntl.h>
# include "libft/libft.h"

typedef struct textsize
{
	int	textlines;
	int	maplines;
	int	longest;
}				t_size;

typedef struct s_map
{
	char	**matrice;
	int		x;
	int		y;
	char	dir;
}				t_map;

typedef struct s_data
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*f;
	char	*c;
}			t_data;

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
int		ft_schr(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_sjoin(char *s1, char *s2);
void	parsing(int ac, char **av, t_data *data, t_map *map);
int		ft_spllen(char **spl);
int		openfile(char *str);
void	error_function(char *str);
t_size	ft_textsize(int fd);
bool	check_extension(char *str, char *ext);
void	check_map(t_map *map);
int		convert_color(char *str);
void	call(int ac, char **av);
char	*c_tos(char c);
bool	char_isdirection(char c);
bool	line_isdigit(char *str);
bool	line_isspace(char *str);
int		exist_player(char *str, int drp);
bool	line_iswall(char *str);
bool	vertical_walls(char *str);
void	checkup_holes(char **str, int j);
void	check_color(char *str);
void	collect_texture(t_data *data, char *dir, char *path);
void	collect_map(t_map *map, int fd, t_size size, char *str);
void	error_function(char *str);
int		openfile(char *str);
bool	str_direction(char *str);
bool	str_color(char *str);
bool	sdigit(char *str);
void	final_pars(t_map *map);
#endif