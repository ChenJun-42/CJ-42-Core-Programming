/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen2 <jchen2@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 14:03:15 by jchen2            #+#    #+#             */
/*   Updated: 2025/01/31 10:48:20 by jchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	zoom_in(t_data *data)
{
	int		i;
	int		points;
	double	scale;

	points = data->matrix->rows * data->matrix->cols;
	i = 0;
	scale = 0.9;
	while (i < points)
	{
		data->point[i].rx *= scale;
		data->point[i].ry *= scale;
		data->point[i].rz *= scale;
		i++;
	}
}

static void	zoom_out(t_data *data)
{
	int		i;
	int		points;
	double	scale;

	points = data->matrix->rows * data->matrix->cols;
	i = 0;
	scale = 1.1;
	while (i < points)
	{
		data->point[i].rx *= scale;
		data->point[i].ry *= scale;
		data->point[i].rz *= scale;
		i++;
	}
}

void	zoom(int keycode, t_data *data)
{
	if (keycode == 61)
		zoom_out(data);
	if (keycode == 45)
		zoom_in(data);
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
