/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen2 <jchen2@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:52:04 by jchen2            #+#    #+#             */
/*   Updated: 2024/11/19 18:33:40 by jchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static	void	print_conversion(char c, va_list args, int *count)
{
	if (c == 'c')
		*count += ft_putchar(va_arg(args, int), 1);
	else if (c == 's')
		*count += ft_putstr(va_arg(args, char *), 1);
	else if (c == 'd' || c == 'i')
		*count += ft_putnbr(va_arg(args, int), 1);
	else if (c == 'p')
		*count += ft_putpointer_hex(va_arg(args, void *));
	else if (c == 'u')
		*count += ft_putunsignedint(va_arg(args, unsigned int), 1);
	else if (c == 'x')
		*count += ft_putlower_hex(va_arg(args, unsigned int));
	else if (c == 'X')
		*count += ft_putupper_hex(va_arg(args, unsigned int));
	else if (c == '%')
		*count += write(1, "%", 1);
}

int	ft_printf(const char *conversions, ...)
{
	va_list	args;
	int		count;
	int		i;

	va_start(args, conversions);
	count = 0;
	i = 0;
	while (conversions[i])
	{
		if (conversions[i] == '%')
		{
			print_conversion(conversions[i + 1], args, &count);
			i++;
		}
		else
		{
			write(1, &conversions[i], 1);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}
/*
int	main(void)
{
	// Test for characters
	char c = 'A';
	ft_printf("Test for character: %c\n", c);

	// Test for string
	char *str = "Hello, World!";
	ft_printf("Test for string: %s\n", str);

	// Test for integer
	int num = -123;
	ft_printf("Test for integer: %d\n", num);

	// Test for unsigned integer
	unsigned int u_num = 123;
	ft_printf("Test for unsigned integer: %u\n", u_num);

	// Test for pointer
	void *ptr = &num;
	ft_printf("Test for pointer: %p\n", ptr);

	// Test for lowercase hex
	unsigned int hex = 255;
	ft_printf("Test for lowercase hex: %x\n", hex);

	// Test for uppercase hex
	ft_printf("Test for uppercase hex: %X\n", hex);

	return 0;
}
*/