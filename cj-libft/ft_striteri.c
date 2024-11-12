/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen2 <jchen2@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 13:49:36 by jchen2            #+#    #+#             */
/*   Updated: 2024/11/12 20:15:54 by jchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}
/*
#include <stdio.h>

void *test(unsigned int i, char *s)
{
	if (i % 2 == 0)
		*s = 'a';
	else
		*s = 'b';
}

int main(void)
{
	char	s[] = "hello world";
	ft_striteri(s,test);
	printf("the string is : %s\n", s);
	return (0);

}
*/