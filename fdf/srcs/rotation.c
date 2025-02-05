/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen2 <jchen2@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:20:42 by jchen2            #+#    #+#             */
/*   Updated: 2025/01/31 10:47:46 by jchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	rotate_x(t_data *data, int keycode)
{
	int		i;
	int		points;
	double	ang;
	double	ty;
	double	tz;

	points = data->matrix->rows * data->matrix->cols;
	if (keycode == 120)
		data->angle_x = 5;
	else
		data->angle_x = -5;
	ang = data->angle_x * (M_PI / 180);
	i = 0;
	while (i < points)
	{
		ty = data->point[i].ry;
		tz = data->point[i].rz;
		data->point[i].ry = ty * cos(ang) - tz * sin(ang);
		data->point[i].rz = ty * sin(ang) + tz * cos(ang);
		i++;
	}
}

static void	rotate_y(t_data *data, int keycode)
{
	int		i;
	int		points;
	double	ang;
	double	tx;
	double	tz;

	points = data->matrix->rows * data->matrix->cols;
	if (keycode == 121)
		data->angle_y = 5;
	else
		data->angle_y = -5;
	ang = data->angle_y * (M_PI / 180);
	i = 0;
	while (i < points)
	{
		tx = data->point[i].rx;
		tz = data->point[i].rz;
		data->point[i].rx = tx * cos(ang) + tz * sin(ang);
		data->point[i].rz = -tx * sin(ang) + tz * cos(ang);
		i++;
	}
}

static void	rotate_z(t_data *data, int keycode)
{
	int		i;
	int		points;
	double	ang;
	double	tx;
	double	ty;

	points = data->matrix->rows * data->matrix->cols;
	if (keycode == 122)
		data->angle_z = 5;
	else
		data->angle_z = -5;
	ang = data->angle_z * (M_PI / 180);
	i = 0;
	while (i < points)
	{
		tx = data->point[i].rx;
		ty = data->point[i].ry;
		data->point[i].rx = tx * cos(ang) - ty * sin(ang);
		data->point[i].ry = tx * sin(ang) + ty * cos(ang);
		i++;
	}
}

void	rotation(int keycode, t_data *data)
{
	if (keycode == 120 || keycode == 113)
		rotate_x(data, keycode);
	if (keycode == 121 || keycode == 119)
		rotate_y(data, keycode);
	if (keycode == 122 || keycode == 101)
		rotate_z(data, keycode);
	if (data->mode == 0)
		isometric_projection(data);
	if (data->mode == 1)
		top_projection(data);
	if (data->mode == 2)
		conic_projection(data);
	if (data->mode == 3)
		side_projection(data);
	if (data->mode == 4)
		front_projection(data);
	set_osx_osy(data);
	draw_img(data);
}
