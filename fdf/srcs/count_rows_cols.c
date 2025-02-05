/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_rows_cols.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen2 <jchen2@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 16:40:47 by jchen2            #+#    #+#             */
/*   Updated: 2025/01/31 10:48:58 by jchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	free_arr(char	**arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free (arr);
}

static void	count_cols(t_matrix *matrix, char *line)
{
	int		i;
	char	**arr;

	arr = ft_split(line, ' ');
	if (!arr)
	{
		free(line);
		return ;
	}
	i = 0;
	while (arr[i] != NULL)
		i++;
	matrix->cols = i;
	free_arr(arr);
}

int	count_rows_cols(char *file, t_matrix *matrix)
{
	int		fd;
	char	*line;

	matrix->rows = 0;
	matrix->cols = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (matrix->rows == 0)
			count_cols(matrix, line);
		free(line);
		matrix->rows++;
	}
	matrix->cell_pixels = 5;
	close(fd);
	return (1);
}
