/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_string_valid.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen2 <jchen2@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 15:15:24 by jchen2            #+#    #+#             */
/*   Updated: 2025/01/02 14:31:57 by jchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//static int	is_str_num(const char *str)
//{
//	int	i;
//	int	len;

//	if (!str || *str == '\0')
//		return (0);
//	len = ft_strlen(str);
//	if (str[0] == ' ' || str[len - 1] == ' ')
//		return (0);
//	i = 0;
//	while (str[i] != '\0')
//	{
//		if (ft_isdigit(str[i]) != 1 && str[i] != ' ')
//			return (0);
//		i++;
//	}
//	return (1);
//}

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

	i = 0;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}

char	**input_string_valid(char **argv)
{
	char	**arr;
	int		count;

	arr = ft_split(argv[1], ' ');
	if (!arr)
	{
		ft_printf("%s\n", "Error");
		exit(EXIT_FAILURE);
	}
	count = 0;
	while (arr[count])
		count++;
	if (is_same(count, arr) == 1)
	{
		free_split(arr);
		ft_printf("%s\n", "Error");
		exit(EXIT_FAILURE);
	}
	return (arr);
}
