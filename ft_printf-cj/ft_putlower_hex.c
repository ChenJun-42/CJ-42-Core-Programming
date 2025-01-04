/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlower_hex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen2 <jchen2@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 20:42:48 by jchen2            #+#    #+#             */
/*   Updated: 2024/11/19 15:27:26 by jchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putlower_hex(unsigned int num)
{
	char	c;
	char	*str_hex;
	int		count;

	str_hex = "0123456789abcdef";
	count = 0;
	if (num >= 16)
		count += ft_putlower_hex(num / 16);
	c = str_hex[num % 16];
	count += write(1, &c, 1);
	return (count);
}
