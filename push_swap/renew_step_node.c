/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renew_step_node.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen2 <jchen2@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 15:51:02 by jchen2            #+#    #+#             */
/*   Updated: 2025/01/04 12:45:19 by jchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*find_max(t_stack **stack_b)
{
	t_node	*max_val;
	t_node	*node1;
	
	node1 = (*stack_b)->top;
	max_val = node1->next;
	while (1)
	{
		if (node1->num > max_val->num)
			max_val = node1;
		node1 = node1->next;
		if (node1 == (*stack_b)->top)
			break ;
	}
	return (max_val);
}

static t_node *cal_in_b(long num, t_stack **stack_b)
{
	t_node	*loop_node;
	t_node	*max_val;

	max_val = find_max(stack_b);
	loop_node = max_val;
	while (loop_node->next != max_val)
	{
		if (num > max_val->num || num < max_val->prev->num)
			return (max_val);
		if (num < loop_node->num && num > loop_node->next->num)
			return (loop_node->next);
		loop_node = loop_node->next;
	}
	return (NULL);
}

void	renew_step_node(t_stack **stack_a, t_stack **stack_b)
{
	long	size_a;
	long	b_step;
	t_node	*node;

	size_a = (*stack_a)->size;
	node = (*stack_a)->top;
	while (1)
	{
		node->b_node = cal_in_b(node->num, stack_b);
		if (node->b_node->index <= (*stack_b)->size / 2)
			b_step = node->b_node->index;
		else
			b_step = (*stack_b)->size - node->b_node->index;
		if (node->index <= size_a / 2)
			node->step = node->index + b_step + 1;
		else
			node->step = size_a - node->index + b_step + 1;
		node = node->next;
		if (node == (*stack_a)->top)
			break ;
	}
}
