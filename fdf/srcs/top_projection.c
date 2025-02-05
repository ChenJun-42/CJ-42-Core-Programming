/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   top_projection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen2 <jchen2@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 14:53:24 by jchen2            #+#    #+#             */
/*   Updated: 2025/01/31 10:46:26 by jchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	top_projection(t_data *data)
{
	int	i;
	int	points;

	points = data->matrix->rows * data->matrix->cols;
	i = 0;
	while (i < points)
	{
		data->point[i].ipx = data->point[i].rx;
		data->point[i].ipy = data->point[i].ry;
		data->point[i].ipz = data->point[i].rz;
		i++;
	}
	data->mode = 1;
}
