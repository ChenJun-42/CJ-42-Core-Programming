/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen2 <jchen2@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 15:55:03 by jchen2            #+#    #+#             */
/*   Updated: 2025/01/02 14:32:20 by jchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	ft_atol(const char *nptr)
{
	long	sign;
	long	result;

	result = 0;
	sign = 1;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		if (result > (LONG_MAX - (*nptr - '0')) / 10)
		{
			if (sign == 1)
				return (LONG_MAX);
			else
				return (LONG_MIN);
		}
		result = result * 10 + *nptr - '0';
		nptr++;
	}
	return (sign * result);
}

static int	is_num(const char *str)
{
	int		i;
	long	num;

	if (!str || *str == '\0')
		return (0);
	if (*str == '-' || *str == '+')
		str++;
	if (*str == '\0')
		return (0);
	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	num = ft_atol(str);
	if (num < INT_MIN || num > INT_MAX)
		return (0);
	return (1);
}

static int	is_same(int argc, char **argv)
{
	int		i;
	int		j;
	size_t	len1;
	size_t	len2;

	i = 1;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			len1 = ft_strlen(argv[i]);
			len2 = ft_strlen(argv[j]);
			if (len1 == len2 && (ft_strncmp(argv[i], argv[j], len1)) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static void	free_split(char	**argv)
{
	int	i;

	if (!argv)
		return ;
	i = 0;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}

void	input_valid(int argc, char **argv)
{
	int	i;

	if (argc < 2 || is_same(argc, argv) == 1)
	{
		ft_printf("%s\n", "Error");
		exit(EXIT_FAILURE);
	}
	i = 0;
	if (argc == 2)
		argv = input_string_valid(argv);
	else
		i++;
	while (argv[i])
	{
		if (is_num(argv[i]) == 0)
		{
			ft_printf("%s\n", "Error");
			exit(EXIT_FAILURE);
		}
		i++;
	}
	if (argc == 2)
		free_split(argv);
}
