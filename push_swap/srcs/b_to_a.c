/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen2 <jchen2@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:06:43 by jchen2            #+#    #+#             */
/*   Updated: 2025/02/02 14:49:36 by jchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*find_max(t_stack **stack_a)
{
	t_node	*max_val;
	t_node	*node1;

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

static t_node	*find_position(long top_num, t_node *max_node)
{
	t_node	*node;

	node = max_node;
	if (top_num > max_node->num || top_num < max_node->next->num)
		return (node->next);
	while (1)
	{
		if (top_num > node->prev->num && top_num < node->num)
			return (node);
		node = node->prev;
		if (node == max_node)
			break ;
	}
	return (node->next);
}

void	push_b_a(t_stack **stack_a, t_stack **stack_b)
{
	t_node	*max_node;
	t_node	*node;
	long	top_num;
	long	r_num;

	max_node = find_max(stack_a);
	top_num = (*stack_b)->top->num;
	node = find_position(top_num, max_node);
	if (node->index >= (*stack_a)->size / 2)
	{
		r_num = (*stack_a)->size - node->index;
		while (r_num--)
			rotate_reverse_ab(stack_a, stack_b, 0);
	}
	else
	{
		r_num = node->index;
		while (r_num--)
			rotate_ab(stack_a, stack_b, 0);
	}
	push_ab(stack_a, stack_b, 0);
}

void	b_to_a(t_stack **stack_a, t_stack **stack_b)
{
	long	size;
	long	min;
	t_node	*min_node;

	size = (*stack_b)->size;
	while (size--)
		push_b_a(stack_a, stack_b);
	min_node = find_min(stack_a);
	if (min_node->index < (*stack_a)->size / 2)
	{
		min = min_node->index;
		while (min--)
			rotate_ab(stack_a, stack_b, 0);
	}
	else
	{
		min = (*stack_a)->size - min_node->index;
		while (min--)
			rotate_reverse_ab(stack_a, stack_b, 0);
	}
}
