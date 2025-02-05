/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_num.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen2 <jchen2@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:12:21 by jchen2            #+#    #+#             */
/*   Updated: 2025/02/01 15:15:49 by jchen2           ###   ########.fr       */
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

int	is_num(const char *str)
{
	int			i;
	long		num;
	const char	*cpy;

	if (!str || *str == '\0')
		return (0);
	if ((str[0] == '-' || str[0] == '+') && str[1] == '0')
		return (0);
	cpy = str;
	if (*str == '-' || *str == '+')
		str++;
	if (*str == '\0' || (str[0] == '0' && str[1] != '\0'))
		return (0);
	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	num = ft_atol(cpy);
	if (num < INT_MIN || num > INT_MAX)
		return (0);
	return (1);
}
