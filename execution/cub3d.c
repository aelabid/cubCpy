// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   cub3d.c                                            :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: aelabid <aelabid@student.42.fr>            +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2022/12/16 07:20:05 by aelabid           #+#    #+#             */
// /*   Updated: 2022/12/18 08:58:35 by aelabid          ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include"../includes/cub3d.h"

int	key_rel(int key)
{
	if (key == 13)
		key_press.w = 0;
	else if (key == 0)
		key_press.a = 0;
	else if (key == 1)
		key_press.s = 0;
	else if (key == 2)
		key_press.d = 0;
	else if (key == 123)
		key_press.left = 0;
	else if (key == 124)
		key_press.right = 0;
	else if (key == 53)
		exit(0);
	return (0);
}
int	register_keys(int key)
{
	if (key == 13)
		key_press.w = 1;
	if (key == 0)
		key_press.a = 1;
	if (key == 1)
		key_press.s = 1;
	if (key == 2)
		key_press.d = 1;
	if (key == 123)
		key_press.left = 1;
	if (key == 124)
		key_press.right = 1;
	return (1);
}

int	quit(void)
{
	exit(0);
	return (0);
}

void	check_texdata(t_data *data)
{
	if(!data->no || !data->so || !data->we || 
				!data->ea || !data->f || !data->c)
		error_function("Incomplet Map");
}

int main(int ac, char **av)
{
	t_data data;
	t_map	map;

	parsing(ac, av, &data, &map);
	check_texdata(&data);

	get_sizes(&map);
	init_info();

	open_window();
	init_player(&map);
	mlx_hook(mlx.win_ptr, 2, 0, register_keys, NULL);
	mlx_hook(mlx.win_ptr, 3, 0, key_rel, NULL);
	mlx_hook(mlx.win_ptr, 17, 0, quit, NULL);
	mlx_loop_hook(mlx.mlx_ptr, handle_keypress, &data);
	mlx_loop(mlx.mlx_ptr);
	free(mlx.mlx_ptr);
}
