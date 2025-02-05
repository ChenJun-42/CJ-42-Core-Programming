/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_height_color.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen2 <jchen2@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 11:15:27 by jchen2            #+#    #+#             */
/*   Updated: 2025/01/31 10:46:10 by jchen2           ###   ########.fr       */
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

static int	hex_to_int(const char *hex_str)
{
	int	result;
	int	value;

	result = 0;
	if (hex_str[0] == '0' && (hex_str[1] == 'x' || hex_str[1] == 'X'))
		hex_str += 2;
	while (*hex_str)
	{
		value = 0;
		if (*hex_str >= '0' && *hex_str <= '9')
			value += *hex_str - '0';
		else if (*hex_str >= 'a' && *hex_str <= 'f')
			value += *hex_str - 'a' + 10;
		else if (*hex_str >= 'A' && *hex_str <= 'F')
			value += *hex_str - 'A' + 10;
		else
			break ;
		result = result * 16 + value;
		hex_str++;
	}
	return (result);
}

static int	split_word(char	*word, t_data *data, int *j)
{
	char	**arr;
	int		cell_size;

	arr = ft_split(word, ',');
	cell_size = data->matrix->cell_pixels;
	if (!arr)
		return (0);
	data->point[*j].z = cell_size * ft_atoi(arr[0]);
	data->point[*j].rz = cell_size * ft_atoi(arr[0]);
	if (!arr[1])
		data->point[*j].color = 0xFFFFFF;
	else
		data->point[*j].color = hex_to_int(arr[1]);
	(*j)++;
	free_arr(arr);
	return (1);
}

static int	split_line(char *line, t_data *data, int *j)
{
	char	**arr;
	int		i;

	arr = ft_split(line, ' ');
	if (!arr)
		return (0);
	i = 0;
	while (arr[i] != NULL)
	{
		if (!split_word(arr[i], data, j))
		{
			free_arr(arr);
			return (0);
		}
		i++;
	}
	free_arr(arr);
	return (1);
}

int	set_height_color(char *file, t_data *data)
{
	int		fd;
	char	*line;
	int		j;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	j = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (!split_line(line, data, &j))
		{
			free(line);
			close(fd);
			return (0);
		}
		free(line);
	}
	close(fd);
	return (1);
}
