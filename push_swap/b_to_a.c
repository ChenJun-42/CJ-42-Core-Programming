/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen2 <jchen2@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 19:05:35 by jchen2            #+#    #+#             */
/*   Updated: 2025/01/04 13:52:18 by jchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*find_maxnum(t_stack **stack_b)
{
	t_node	*init_node;
	t_node	*loop_node;
	t_node	*max_node;

	if (!stack_b || !(*stack_b))
		return (NULL);
	init_node = (*stack_b)->top;
	max_node = (*stack_b)->top;
	loop_node = (*stack_b)->top->next;
	while (loop_node != init_node)
	{
		if (max_node->num < loop_node->num)
			max_node = loop_node;
		loop_node = loop_node->next;
	}
	return (max_node);
}

void	b_to_a(t_stack **stack_a, t_stack **stack_b)
{
	t_node	*max_node;
	long	size_b;
	long	r_num;

	max_node = find_maxnum(stack_b);
	size_b = (*stack_b)->size;
	if (max_node->index <= size_b / 2)
	{
		r_num = max_node->index;
		while (r_num--)
			rotate_ab(stack_a, stack_b, 1);
		while (size_b--)
			push_ab(stack_a, stack_b, 0);
	}
	else
	{
		r_num = size_b - max_node->index;
		while (r_num--)
			rotate_reverse_ab(stack_a, stack_b, 1);
		while (size_b--)
			push_ab(stack_a, stack_b, 0);
	}
}
