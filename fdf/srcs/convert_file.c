/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen2 <jchen2@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 09:27:25 by jchen2            #+#    #+#             */
/*   Updated: 2025/01/28 14:10:34 by jchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	set_x_y(t_data *data)
{
	int	row;
	int	col;
	int	cell_size;
	int	index;

	if (!data || !data->matrix || !data->point)
		return (0);
	row = 0;
	index = 0;
	cell_size = data->matrix->cell_pixels;
	while (row < data->matrix->rows)
	{
		col = 0;
		while (col < data->matrix->cols)
		{
			data->point[index].y = row * cell_size;
			data->point[index].x = col * cell_size;
			data->point[index].ry = row * cell_size;
			data->point[index].rx = col * cell_size;
			index++;
			col++;
		}
		row++;
	}
	return (1);
}

int	convert_file(char *file, t_data *data)
{
	int	points;

	if (!count_rows_cols(file, data->matrix))
		return (0);
	points = data->matrix->cols * data->matrix->rows;
	data->point = (t_point *)ft_calloc(points, sizeof(t_point));
	if (!data->point)
		return (0);
	if (!set_x_y(data))
		return (0);
	if (!set_height_color(file, data))
	{
		free(data->point);
		return (0);
	}
	return (1);
}
