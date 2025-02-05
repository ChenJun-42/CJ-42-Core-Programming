/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen2 <jchen2@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 17:35:11 by jchen2            #+#    #+#             */
/*   Updated: 2025/01/28 14:42:26 by jchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	translate_right(t_data *data)
{
	int		i;
	int		points;

	points = data->matrix->rows * data->matrix->cols;
	data->offset_x += 10;
	i = 0;
	while (i < points)
	{
		data->point[i].osx = data->point[i].osx + 10;
		i++;
	}
	draw_img(data);
}

void	translate_left(t_data *data)
{
	int		i;
	int		points;

	points = data->matrix->rows * data->matrix->cols;
	data->offset_x -= 10;
	i = 0;
	while (i < points)
	{
		data->point[i].osx = data->point[i].osx - 10;
		i++;
	}
	draw_img(data);
}

void	translate_top(t_data *data)
{
	int		i;
	int		points;

	points = data->matrix->rows * data->matrix->cols;
	data->offset_y -= 10;
	i = 0;
	while (i < points)
	{
		data->point[i].osy = data->point[i].osy - 10;
		i++;
	}
	draw_img(data);
}

void	translate_bottom(t_data *data)
{
	int		i;
	int		points;

	points = data->matrix->rows * data->matrix->cols;
	i = 0;
	data->offset_y += 10;
	while (i < points)
	{
		data->point[i].osy = data->point[i].osy + 10;
		i++;
	}
	draw_img(data);
}

void	translation(int keycode, t_data *data)
{
	if (keycode == 65362)
		translate_top(data);
	if (keycode == 65364)
		translate_bottom(data);
	if (keycode == 65363)
		translate_right(data);
	if (keycode == 65361)
		translate_left(data);
}
