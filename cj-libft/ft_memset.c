/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen2 <jchen2@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 10:03:50 by jchen2            #+#    #+#             */
/*   Updated: 2024/11/11 20:44:39 by jchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		*ptr = c;
		ptr++;
		i++;
	}
	return (s);
}
/*
#include <stdio.h>

int	main(void)
{
	unsigned char	x[20];

	ft_memset(x, 'A', 10);
	x[10] = '\0';
	printf("%s\n", x);
	return (0);
}
*/