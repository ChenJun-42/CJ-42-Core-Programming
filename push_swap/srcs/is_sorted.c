/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen2 <jchen2@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:05:29 by jchen2            #+#    #+#             */
/*   Updated: 2025/02/02 14:52:05 by jchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	t_node	*node1;
	t_node	*node2;

	if (stack->size <= 1)
		return (1);
	node1 = stack->top;
	node2 = node1->next;
	while (node2 != stack->top)
	{
		if (node2->num < node1->num)
			return (0);
		node1 = node2;
		node2 = node2->next;
	}
	return (1);
}
