/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen2 <jchen2@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 17:52:45 by jchen2            #+#    #+#             */
/*   Updated: 2024/11/12 17:00:31 by jchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst == NULL || del == NULL)
		return ;
	del(lst->content);
	free(lst);
}
/*
#include <stdio.h>

void	del(void	*content)
{
	printf("delete the content: %s\n", (char *)content);
	free(content);
}

t_list	*ft_lstnew(void *content)
{
	t_list	*lstnew;

	lstnew = (t_list *)malloc(sizeof(t_list));
	if (!lstnew)
		return (NULL);
	lstnew->content = content;
	lstnew->next = NULL;
	return (lstnew);
}

int	main(void)
{
	t_list	*head = ft_lstnew(malloc(12));
	if (!head)
		return (1);
	sprintf((char *)head->content, "hello world");
	ft_lstdelone(head, &del);
	return (0);
}
*/