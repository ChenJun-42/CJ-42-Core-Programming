/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen2 <jchen2@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 13:48:27 by jchen2            #+#    #+#             */
/*   Updated: 2024/11/12 19:59:36 by jchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

static int	len_substr(char const *ptr1, char const *ptr2)
{
	int	len;

	len = 0;
	while (ptr2 != ptr1)
	{
		len++;
		ptr2++;
	}
	return (len);
}

static int	num_substr(char const *s, char c)
{
	char const	*ptr1;
	char const	*ptr2;
	int			len;
	int			num;

	ptr1 = s;
	ptr2 = ptr1;
	len = 0;
	num = 0;
	while (*ptr1)
	{
		if (*ptr1 == c)
		{
			len = len_substr(ptr1, ptr2);
			ptr2 = ptr1 + 1;
			if (len > 0)
				num++;
		}
		ptr1++;
	}
	if (len_substr(ptr1, ptr2) > 0)
		num++;
	return (num);
}

static char	*set_value(char *ptr2, int len)
{
	char	*arr;
	int		j;

	arr = (char *)malloc((len + 1));
	if (!arr)
		return (NULL);
	j = 0;
	while (j < len)
	{
		arr[j] = ptr2[j];
		j++;
	}
	arr[j] = '\0';
	return (arr);
}

static char	**set_str_mem(char const *s, char c, char **arr)
{
	char	*ptr1;
	char	*ptr2;
	int		i;

	ptr1 = (char *) s;
	ptr2 = ptr1;
	i = 0;
	while (*ptr1)
	{
		if (*ptr1 == c)
		{
			if (len_substr(ptr1, ptr2) > 0)
			{
				arr[i] = set_value(ptr2, len_substr(ptr1, ptr2));
				i++;
			}
			ptr2 = ptr1 + 1;
		}
		ptr1++;
	}
	if (len_substr(ptr1, ptr2) > 0)
		arr[i] = set_value(ptr2, len_substr(ptr1, ptr2));
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	int		num;
	char	**arr;

	if (s == NULL)
		return (NULL);
	num = num_substr(s, c);
	arr = (char **)malloc((num + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	arr = set_str_mem(s, c, arr);
	arr[num] = NULL;
	return (arr);
}
/*
#include <stdio.h>

int main(void)
{
    char *str = "--Hello--world--";
    char delimiter = '-';
    char **result;
    int i = 0;

    // Call ft_split to split the string by the delimiter
    result = ft_split(str, delimiter);

    if (result)
    {
        // Print the split substrings
        while (result[i])
        {
            printf("Substring %d: %s\n", i + 1, result[i]);
            free(result[i]);  // Free each substring after printing
            i++;
        }
        free(result);  // Free the array of string pointers
    }
    else
    {
        printf("Memory allocation failed.\n");
    }

    return 0;
}
*/