/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen2 <jchen2@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:10:09 by jchen2            #+#    #+#             */
/*   Updated: 2024/11/19 15:25:28 by jchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putnbr(int n, int fd)
{
	int	count;

	if (n == -2147483648)
		return (ft_putstr("-2147483648", 1));
	count = 0;
	if (n < 0)
	{
		count += write(fd, "-", 1);
		n = -n;
	}
	if (n > 9)
		count += ft_putnbr(n / 10, fd);
	count += write(fd, &(char){n % 10 + '0'}, 1);
	return (count);
}
