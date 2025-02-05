/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen2 <jchen2@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:40:48 by jchen2            #+#    #+#             */
/*   Updated: 2025/01/31 10:48:34 by jchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_menu(void *mlx, void *win)
{
	int		color;
	char	*font_name;

	font_name = "-misc-fixed-medium-r-normal--20-200-75-75-c-100-iso8859-9";
	color = 0xFFFFFF;
	mlx_set_font(mlx, win, font_name);
	mlx_string_put(mlx, win, 20, 20, color, "Controls Keycode:");
	mlx_string_put(mlx, win, 20, 40, color, "f/s/t/c/i: Change Projection");
	mlx_string_put(mlx, win, 20, 60, color, "+/-: Zoom In/Out");
	mlx_string_put(mlx, win, 20, 80, color, "Arrow Keys: Move Model");
	mlx_string_put(mlx, win, 20, 100, color, "q/w/e/x/y/z: Rotate Model");
	mlx_string_put(mlx, win, 20, 120, color, "r: Reset View");
	mlx_string_put(mlx, win, 20, 140, color, "ESC: Exit Program");
}

static int	key_press(int keycode, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (keycode == 65307)
	{
		free_data(data);
		exit(EXIT_SUCCESS);
	}
	if (keycode == 116 || keycode == 105
		|| keycode == 99 || keycode == 102 || keycode == 115)
		projection(keycode, data);
	if (keycode == 61 || keycode == 45)
		zoom(keycode, data);
	if (keycode == 65361 || keycode == 65362
		|| keycode == 65363 || keycode == 65364)
		translation(keycode, data);
	if (keycode == 120 || keycode == 121 || keycode == 122
		|| keycode == 113 || keycode == 119 || keycode == 101)
		rotation(keycode, data);
	if (keycode == 114)
		reset(data);
	draw_menu(data->mlx, data->win);
	return (0);
}

static int	close_window(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	free_data(data);
	exit(EXIT_SUCCESS);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data		data;
	t_matrix	matrix;

	if (argc != 2)
		exit(EXIT_FAILURE);
	data.matrix = &matrix;
	if (!initial_data(&data, argv[1]))
	{
		free_data(&data);
		exit(EXIT_FAILURE);
	}
	mlx_put_image_to_window(data.mlx, data.win,
		data.img, 0, 0);
	mlx_key_hook(data.win, key_press, &data);
	mlx_hook(data.win, 17, 0, close_window, &data);
	mlx_loop(data.mlx);
	return (0);
}
