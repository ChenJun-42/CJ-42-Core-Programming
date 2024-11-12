/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen2 <jchen2@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 10:05:57 by jchen2            #+#    #+#             */
/*   Updated: 2024/11/09 10:05:59 by jchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strrchr(const char *s, int c)
{
	const char	*ptr;

	ptr = NULL;
	while (*s)
	{
		if (*s == (char)c)
			ptr = s;
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return ((char *)ptr);
}
/*
#include <stdio.h>

int main()
{
	char *x;

	x = ft_strrchr("hello", 'l');
	printf("%s\n", x);
	return (0);
}
*/