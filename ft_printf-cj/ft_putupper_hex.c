/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putupper_hex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen2 <jchen2@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 20:52:20 by jchen2            #+#    #+#             */
/*   Updated: 2024/11/19 16:11:12 by jchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putupper_hex(unsigned int num)
{
	char	c;
	char	*str_hex;
	int		count;

	count = 0;
	str_hex = "0123456789ABCDEF";
	if (num >= 16)
		count += ft_putupper_hex(num / 16);
	c = str_hex[num % 16];
	count += write(1, &c, 1);
	return (count);
}
