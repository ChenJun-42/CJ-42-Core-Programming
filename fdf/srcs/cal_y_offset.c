/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal_y_offset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen2 <jchen2@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 11:19:34 by jchen2            #+#    #+#             */
/*   Updated: 2025/01/31 10:44:13 by jchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static double	find_y_min(t_data *data)
{
	int		points;
	int		i;
	double	y_min;

	points = data->matrix->cols * data->matrix->rows;
	i = 0;
	y_min = DBL_MAX;
	while (i < points)
	{
		if (data->point[i].ipy < y_min)
			y_min = data->point[i].ipy;
		i++;
	}
	return (y_min);
}

static double	find_y_max(t_data *data)
{
	int		points;
	int		i;
	double	y_max;

	points = data->matrix->cols * data->matrix->rows;
	i = 0;
	y_max = -DBL_MAX;
	while (i < points)
	{
		if (data->point[i].ipy > y_max)
			y_max = data->point[i].ipy;
		i++;
	}
	return (y_max);
}

double	cal_y_offset(t_data *data)
{
	double	y_min;
	double	y_max;
	double	y_offset;
	double	y_range;

	y_min = find_y_min(data);
	y_max = find_y_max(data);
	y_range = (y_max - y_min);
	if (y_range > data->height)
		y_offset = y_min * (-1);
	else
		y_offset = y_min * (-1) + (data->height - y_range) / 2;
	return (y_offset);
}
