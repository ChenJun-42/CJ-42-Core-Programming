/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen2 <jchen2@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 12:40:00 by jchen2            #+#    #+#             */
/*   Updated: 2025/01/27 19:11:53 by jchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	projection(int keycode, t_data *data)
{
	if (keycode == 116)
		top_projection(data);
	if (keycode == 105)
		isometric_projection(data);
	if (keycode == 99)
		conic_projection(data);
	if (keycode == 102)
		front_projection(data);
	if (keycode == 115)
		side_projection(data);
	set_osx_osy(data);
	draw_img(data);
}
