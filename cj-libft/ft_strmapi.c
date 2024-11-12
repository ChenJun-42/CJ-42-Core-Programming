/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen2 <jchen2@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 11:49:56 by jchen2            #+#    #+#             */
/*   Updated: 2024/11/10 14:08:22 by jchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
static char	index_char(unsigned int i, char c)
{
	return (i + c);
}
*/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new_str;
	size_t	i;
	size_t	len;

	len = ft_strlen(s);
	new_str = (char *)malloc(len + 1);
	if (!new_str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new_str[i] = f(i, s[i]);
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
/*
#include <stdio.h>

int	main()
{
	char	*s = "hello";
	char	*result;

	result = ft_strmapi(s, index_char);
	if (result)
	{
		printf("%s\n", result);
		printf("original string%s\n", s);
		free(result);
	}
	else
	{
		printf("Memory allocation failed\n");
	}
}
*/