/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric_projection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen2 <jchen2@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 09:33:07 by jchen2            #+#    #+#             */
/*   Updated: 2025/01/28 14:06:45 by jchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	isometric_projection(t_data *data)
{
	double	tx;
	double	ty;
	int		i;
	int		points;

	points = data->matrix->rows * data->matrix->cols;
	i = 0;
	while (i < points)
	{
		tx = data->point[i].rx;
		ty = data->point[i].ry;
		data->point[i].ipx = ((tx - ty) * cos(M_PI / 6));
		data->point[i].ipy = ((tx + ty) * sin(M_PI / 6) - data->point[i].rz);
		data->point[i].ipz = data->point[i].rz;
		i++;
	}
	data->mode = 0;
}
