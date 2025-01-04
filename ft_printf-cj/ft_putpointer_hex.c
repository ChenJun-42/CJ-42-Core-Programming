/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer_hex.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen2 <jchen2@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 18:10:53 by jchen2            #+#    #+#             */
/*   Updated: 2024/11/24 11:55:43 by jchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_re(unsigned long addr, char *hex_di)
{
	int	count;

	count = 0;
	if (addr == 0)
		return (count);
	count += ft_re(addr / 16, hex_di);
	write (1, &hex_di[addr % 16], 1);
	return (count + 1);
}

int	ft_putpointer_hex(void *p)
{
	unsigned long	address;
	char			*hex_digits;
	int				count;

	if (!p)
		return (write(1, "(nil)", 5));
	address = (unsigned long)p;
	hex_digits = "0123456789abcdef";
	count = 0;
	count += write(1, "0x", 2);
	if (address == 0)
		count += write(1, "0", 1);
	else
		count += ft_re(address, hex_digits);
	return (count);
}
