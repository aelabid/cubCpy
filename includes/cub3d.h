/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelabid <aelabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 07:14:53 by aelabid           #+#    #+#             */
/*   Updated: 2023/01/13 01:02:00 by aelabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

// includes
#include "../pars/cub.h"
# include"mlx.h"
# include<stdlib.h>
# include<math.h>
# include<stdio.h>
# include <unistd.h>
# include <math.h>
// # include"get_next_line.h"

// #include <X11/X.h>
// #include <X11/keysym.h>

// Macros
#define RED_PIXEL 0x00FF0000
#define GREEN_PIXEL 0xFF00
#define WHITE_PIXEL 0xFFFFFF
#define REC_SIZE 32

// typedef
typedef struct s_mlx
{
	void	*img;
	void	*mlx_ptr;
	void	*win_ptr;
}	t_mlx;

typedef struct	s_img {
	void	*img;
	char 	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_texture {
	void	*img;
	int 	height;
	int		width;
	char	*path;
	int 	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_texture;

typedef struct s_rect
{
	int	x;
	int	y;
	int rec_size;
	int color;
}	t_rect;

typedef struct s_wall
{
	double	x;
	double	y;
	double height;
	double width;
}	t_wall;

typedef struct s_player
{
	double x;
	double y;
	int size;
	int turn_dir;
	int walk_dir;
	double rotate_angle;
	int move_speed;
	double rotat_speed;
}	t_player;

typedef struct s_winSizes
{
	int nb_row;
	int nb_col;
	int win_h;
	int win_w;
}	t_winSizes;

typedef	struct s_point
{
	double	x;
	double	y;
}	t_point;

typedef struct s_info
{
	double	fov;
	double	ray_strip;
	int	num_ray;
}	t_info;

typedef	struct s_ray
{
	double	ray_angle;
	int		isUp;
	int		isDown;
	int		isDownL;
	int		isRight;
	int		isLeft;
	double	distance;
	double	finale_distance;
	int		is_horizontal;
}	t_ray;

typedef struct s_key
{
	int	w;
	int s;
	int a;
	int d;
	int left;
	int right;
} t_key;


//typedef for test
typedef struct t_iso
{
	int		height;
	int		color;
}	t_iso;


//global variables
t_player p;
t_mlx   mlx;
t_img img;
t_winSizes win;
char	**matrix;
t_info	info;
t_ray	ray;
t_texture texture[4];
t_point	c_wall;
t_texture right_text;
t_key	key_press;
//functions 

int	handle_keypress(t_data *data);
int render_colored_rect(t_rect rect);
int render_empty_rect(t_rect rect);
void	my_mlx_pixel_put(int x, int y, int color);
int render_map();
void	get_sizes_matrix(char *path);
void    init_player(t_map *map);
// void update_player(int key);
void    open_window();
void    render_image(t_data data);
void  render_player(t_data data);
void  move_player();
void  move_sides();
int is_wall(double x, double y);
void    init_info();
void    render_lines(t_data data);
double  norm_angle(double ray_angle);
void    color_background(t_data data);
void    get_images(t_data data);
void    get_sizes(t_map  *map);
//functions for test
t_iso	*creat_line(char *str, int numcol);
char	**ft_split(char const *s, char c);
int	ft_atoi(const char *c);
int	ft_numofcolumns(char *s, char spl);
int	numberofrows(int fd, int *nbrow);
t_iso	**create_matrix(int numrow, int fd);
int	number_col_matx(t_iso *mat);
int	openfd(char *ac);
int get_rows(int fd);
void DDA(int X0, int Y0, int X1, int Y1, int col);
int render_wall(t_wall wall);
// t_texture	get_right_wall();
#endif