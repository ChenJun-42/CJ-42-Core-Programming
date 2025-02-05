/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen2 <jchen2@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 14:21:59 by jchen2            #+#    #+#             */
/*   Updated: 2025/02/02 14:58:12 by jchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*find_min(t_stack **stack_a)
{
	t_node	*min_val;
	t_node	*node1;

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

void	sort_four_node(t_stack **stack_a, t_stack **stack_b)
{
	t_node	*min_node;
	long	r_a;

	min_node = find_min(stack_a);
	if (min_node->index <= (*stack_a)->size / 2)
	{
		r_a = min_node->index;
		while (r_a--)
			rotate_ab(stack_a, stack_b, 0);
		push_ab(stack_a, stack_b, 1);
	}
	else
	{
		r_a = (*stack_a)->size - min_node->index;
		while (r_a--)
			rotate_reverse_ab(stack_a, stack_b, 0);
		push_ab(stack_a, stack_b, 1);
	}
	sort_three_node(stack_a, stack_b);
	push_ab(stack_a, stack_b, 0);
}
