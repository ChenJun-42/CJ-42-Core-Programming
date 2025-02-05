/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen2 <jchen2@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:55:39 by jchen2            #+#    #+#             */
/*   Updated: 2025/01/28 15:00:37 by jchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	reset(t_data *data)
{
	int	i;
	int	points;

	points = data->matrix->rows * data->matrix->cols;
	i = 0;
	while (i < points)
	{
		data->point[i].rx = data->point[i].x;
		data->point[i].ry = data->point[i].y;
		data->point[i].rz = data->point[i].z;
		i++;
	}
	data->angle_x = 0;
	data->angle_y = 0;
	data->angle_z = 0;
	data->offset_x = 0;
	data->offset_y = 0;
	isometric_projection(data);
	set_osx_osy(data);
	draw_img(data);
}
