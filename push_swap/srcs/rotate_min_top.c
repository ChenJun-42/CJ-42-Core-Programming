/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_min_top.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen2 <jchen2@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 12:39:02 by jchen2            #+#    #+#             */
/*   Updated: 2025/02/02 14:56:47 by jchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*find_min(t_stack **stack_a)
{
	t_node	*min_val;
	t_node	*node1;

	if (!(*stack_a) || (*stack_a)->top == NULL)
		return (NULL);
	node1 = (*stack_a)->top;
	min_val = node1->next;
	while (1)
	{
		if (node1->num < min_val->num)
			min_val = node1;
		node1 = node1->next;
		if (node1 == (*stack_a)->top)
			break ;
	}
	return (min_val);
}

void	rotate_min_top(t_stack **stack_a, t_stack **stack_b)
{
	t_node	*node;
	long	ra;

	node = find_min(stack_a);
	if (node->index > (*stack_a)->size / 2)
	{
		ra = (*stack_a)->size - node->index;
		while (ra--)
			rotate_reverse_ab(stack_a, stack_b, 0);
	}
	else
	{
		ra = node->index;
		while (ra--)
			rotate_ab(stack_a, stack_b, 0);
	}
}
