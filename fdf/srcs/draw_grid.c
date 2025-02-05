/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen2 <jchen2@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:24:23 by jchen2            #+#    #+#             */
/*   Updated: 2025/01/31 10:45:07 by jchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	draw_horizontal_lines(t_data *data)
{
	int		col;
	int		row;
	t_point	p0;
	t_point	p1;

	row = 0;
	while (row < data->matrix->rows)
	{
		col = 0;
		while (col < data->matrix->cols - 1)
		{
			p0 = data->point[row * data->matrix->cols + col];
			p1 = data->point[row * data->matrix->cols + col + 1];
			brehensam_line(data, p0, p1);
			col++;
		}
		row++;
	}
}

static void	draw_vertical_lines(t_data *data)
{
	int		col;
	int		row;
	t_point	p0;
	t_point	p1;

	col = 0;
	while (col < data->matrix->cols)
	{
		row = 0;
		while (row < (data->matrix->rows - 1))
		{
			p0 = data->point[row * data->matrix->cols + col];
			p1 = data->point[(row + 1) * data->matrix->cols + col];
			brehensam_line(data, p0, p1);
			row++;
		}
		col++;
	}
}

void	draw_grid(t_data *data)
{
	draw_horizontal_lines(data);
	draw_vertical_lines(data);
}
