/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conic_projection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen2 <jchen2@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 15:25:20 by jchen2            #+#    #+#             */
/*   Updated: 2025/01/31 10:44:38 by jchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	conic_projection(t_data *data)
{
	int	i;
	int	points;

	points = data->matrix->rows * data->matrix->cols;
	i = 0;
	while (i < points)
	{
		if (data->point[i].z != 0)
		{
			data->point[i].ipx
				= (data->point[i].x * data->depth) / data->point[i].z;
			data->point[i].ipy
				= (data->point[i].y * data->depth) / data->point[i].z;
			data->point[i].ipz = data->point[i].z;
		}
		else
		{
			data->point[i].ipx = data->point[i].x;
			data->point[i].ipy = data->point[i].y;
			data->point[i].ipz = data->point[i].z;
		}
		i++;
	}
	data->mode = 2;
}
