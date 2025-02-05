/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen2 <jchen2@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 15:55:03 by jchen2            #+#    #+#             */
/*   Updated: 2025/02/02 14:51:52 by jchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_same(int argc, char **argv)
{
	int		i;
	int		j;
	char	*s1;
	char	*s2;

	i = 1;
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

void	print_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

void	input_valid(int argc, char **argv)
{
	int		i;

	if (argc < 2)
		exit(EXIT_SUCCESS);
	if (argc == 2)
	{
		if (input_string_valid(argv) == 0)
			print_error();
	}
	else
	{
		if (is_same(argc, argv) == 1)
			print_error();
		i = 1;
		while (argv[i])
		{
			if (is_num(argv[i]) == 0)
				print_error();
			i++;
		}
	}
}
