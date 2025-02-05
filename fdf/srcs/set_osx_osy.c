/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_osx_osy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen2 <jchen2@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:55:47 by jchen2            #+#    #+#             */
/*   Updated: 2025/01/28 14:17:37 by jchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_osx_osy(t_data *data)
{
	int		i;
	int		points;
	double	x_offset;
	double	y_offset;

	i = 0;
	points = data->matrix->rows * data->matrix->cols;
	x_offset = cal_x_offset(data);
	y_offset = cal_y_offset(data);
	while (i < points)
	{
		data->point[i].osx
			= (int)round(data->point[i].ipx + x_offset + data->offset_x);
		data->point[i].osy
			= (int)round(data->point[i].ipy + y_offset + data->offset_y);
		i++;
	}
}
