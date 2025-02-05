/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renew_step_node_group.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen2 <jchen2@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:43:58 by jchen2            #+#    #+#             */
/*   Updated: 2025/02/02 14:53:42 by jchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*find_max(t_stack **stack_a)
{
	t_node	*max_val;
	t_node	*node1;

	if (!(*stack_a) || (*stack_a)->top == NULL)
		return (NULL);
	node1 = (*stack_a)->top;
	max_val = node1->next;
	while (1)
	{
		if (node1->num > max_val->num)
			max_val = node1;
		node1 = node1->next;
		if (node1 == (*stack_a)->top)
			break ;
	}
	return (max_val);
}

static t_node	*cal_in_a(long num, t_stack **stack_a)
{
	t_node	*loop_node;
	t_node	*max_val;

	if (!(*stack_a) || (*stack_a)->top == NULL)
		return (NULL);
	max_val = find_max(stack_a);
	if (num > max_val->num || num < max_val->next->num)
		return (max_val->next);
	loop_node = max_val;
	while (loop_node->prev != max_val)
	{
		if (num < loop_node->num && num > loop_node->prev->num)
			return (loop_node);
		loop_node = loop_node->prev;
	}
	return (max_val);
}

static long	step_in_a(t_stack **stack_a, t_node *node)
{
	long	a_step;

	a_step = 0;
	node->b_node = cal_in_a(node->num, stack_a);
	if (node->b_node != NULL)
	{
		if (node->b_node->index <= (*stack_a)->size / 2)
			a_step = node->b_node->index;
		else
			a_step = (*stack_a)->size - node->b_node->index;
	}
	return (a_step);
}

void	renew_step_node_group(t_stack **stack_a,
		t_stack **stack_b, long x, long y)
{
	long	size_b;
	long	a_step;
	t_node	*node;

	size_b = (*stack_b)->size;
	node = (*stack_b)->top;
	while (1)
	{
		if (node->num_index >= x && node->num_index < y)
		{
			a_step = step_in_a(stack_a, node);
			if (node->index <= size_b / 2)
				node->step = node->index + a_step + 1;
			else
				node->step = size_b - node->index + a_step + 1;
		}
		node = node->next;
		if (node == (*stack_b)->top)
			break ;
	}
}
