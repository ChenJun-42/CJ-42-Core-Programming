/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   side_projection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen2 <jchen2@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:39:44 by jchen2            #+#    #+#             */
/*   Updated: 2025/01/31 10:46:32 by jchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	side_projection(t_data *data)
{
	int	i;
	int	points;

	points = data->matrix->rows * data->matrix->cols;
	i = 0;
	while (i < points)
	{
		data->point[i].ipx = data->point[i].ry;
		data->point[i].ipy = data->height - data->point[i].rz;
		data->point[i].ipz = data->point[i].rx;
		i++;
	}
	data->mode = 3;
}
