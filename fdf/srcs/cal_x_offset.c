/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal_x_offset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen2 <jchen2@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 10:38:36 by jchen2            #+#    #+#             */
/*   Updated: 2025/01/28 13:33:18 by jchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static double	find_x_min(t_data *data)
{
	int		points;
	int		i;
	double	x_min;

	points = data->matrix->cols * data->matrix->rows;
	i = 0;
	x_min = DBL_MAX;
	while (i < points)
	{
		if (data->point[i].ipx < x_min)
			x_min = data->point[i].ipx;
		i++;
	}
	return (x_min);
}

static double	find_x_max(t_data *data)
{
	int		points;
	int		i;
	double	x_max;

	points = data->matrix->cols * data->matrix->rows;
	i = 0;
	x_max = -DBL_MAX;
	while (i < points)
	{
		if (data->point[i].ipx > x_max)
			x_max = data->point[i].ipx;
		i++;
	}
	return (x_max);
}

double	cal_x_offset(t_data *data)
{
	double	x_min;
	double	x_max;
	double	x_offset;
	double	x_range;

	x_min = find_x_min(data);
	x_max = find_x_max(data);
	x_range = (x_max - x_min);
	if (x_range > data->width)
		x_offset = x_min * (-1);
	else
		x_offset = x_min * (-1) + (data->width - x_range) / 2;
	return (x_offset);
}
