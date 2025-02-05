/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inital_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen2 <jchen2@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 10:29:57 by jchen2            #+#    #+#             */
/*   Updated: 2025/01/28 14:08:27 by jchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	initial_data(t_data *data, char *file)
{
	data->width = 2980;
	data->height = 2000;
	data->depth = 500;
	data->angle_x = 0;
	data->angle_y = 0;
	data->angle_z = 0;
	data->offset_x = 0;
	data->offset_y = 0;
	data->mlx = mlx_init();
	if (!data->mlx)
		return (0);
	data->win = mlx_new_window(data->mlx, data->width, data->height, "Image");
	if (!data->win)
		return (0);
	data->img = NULL;
	if (!convert_file(file, data))
		return (0);
	isometric_projection(data);
	set_osx_osy(data);
	draw_img(data);
	return (1);
}
