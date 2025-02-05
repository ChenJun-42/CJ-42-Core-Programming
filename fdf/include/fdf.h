/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen2 <jchen2@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 14:15:40 by jchen2            #+#    #+#             */
/*   Updated: 2025/01/31 10:43:37 by jchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "mlx.h"
# include "get_next_line.h"
# include "libft.h"
# include <fcntl.h>
# include <math.h>
# include <float.h>

# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

typedef struct s_point
{
	double	x;
	double	y;
	double	z;
	double	rx;
	double	ry;
	double	rz;
	double	ipx;
	double	ipy;
	double	ipz;
	int		osx;
	int		osy;
	int		color;
}	t_point;

typedef struct s_state
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	points;
}	t_bh_state;

typedef struct s_rgb
{
	int	start_r;
	int	start_g;
	int	start_b;
	int	end_r;
	int	end_g;
	int	end_b;
}	t_rgb;

typedef struct s_matrix
{
	int		rows;
	int		cols;
	int		cell_pixels;
}	t_matrix;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			width;
	int			height;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			depth;
	int			mode;
	int			angle_x;
	int			angle_y;
	int			angle_z;
	int			offset_x;
	int			offset_y;
	t_point		*point;
	t_matrix	*matrix;
}	t_data;

int		initial_data(t_data *data, char *file);
int		convert_file(char *file, t_data *data);
int		count_rows_cols(char *file, t_matrix *matrix);
int		set_height_color(char *file, t_data *data);
double	cal_x_offset(t_data *data);
double	cal_y_offset(t_data *data);
void	projection(int keycode, t_data *data);
void	translation(int keycode, t_data *data);
void	rotation(int keycode, t_data *data);
void	isometric_projection(t_data *data);
void	top_projection(t_data *data);
void	side_projection(t_data *data);
void	front_projection(t_data *data);
void	conic_projection(t_data *data);
void	zoom(int keycode, t_data *data);
void	draw_grid(t_data *data);
void	draw_img(t_data *data);
void	set_osx_osy(t_data *data);
void	brehensam_line(t_data *data, t_point p0, t_point p1);
void	free_data(t_data *data);
void	reset(t_data *data);

#endif
