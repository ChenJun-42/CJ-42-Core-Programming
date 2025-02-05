/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_string_valid.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen2 <jchen2@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 15:15:24 by jchen2            #+#    #+#             */
/*   Updated: 2025/02/02 14:51:43 by jchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_num(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
	{
		if (is_num(arr[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

static int	is_same(int argc, char **argv)
{
	int		i;
	int		j;
	char	*s1;
	char	*s2;

	i = 0;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			s1 = argv[i];
			s2 = argv[j];
			if (*s1 == '+')
				s1++;
			if (*s2 == '+')
				s2++;
			if (ft_strlen(s1)
				== ft_strlen(s2) && (ft_strncmp(s1, s2, ft_strlen(s1))) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	input_string_valid(char **argv)
{
	char	**arr;
	int		count;

	arr = ft_split(argv[1], ' ');
	if (!arr)
		return (0);
	count = 0;
	while (arr[count])
		count++;
	if (is_same(count, arr) == 1 || check_num(arr) == 0)
	{
		free_split(arr);
		return (0);
	}
	free_split(arr);
	return (1);
}
