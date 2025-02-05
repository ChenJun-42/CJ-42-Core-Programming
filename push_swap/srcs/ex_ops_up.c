/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_ops_up.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen2 <jchen2@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 10:57:06 by jchen2            #+#    #+#             */
/*   Updated: 2025/02/02 14:50:49 by jchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	cal_rrotb(t_stack **stack_b, t_node *node)
{
	long	r_a;
	long	r_b;
	long	rr_b;
	long	val;

	r_a = node->index;
	r_b = (*stack_b)->size - node->b_node->index;
	val = 2 * node->b_node->index - (*stack_b)->size;
	rr_b = INT_MAX;
	if ((r_a < (*stack_b)->size) && r_a > val)
		rr_b = node->b_node->index - r_a;
	else if (r_a > (*stack_b)->size && val < (r_a % (*stack_b)->size))
		rr_b = node->b_node->index - (r_a % (*stack_b)->size);
	return (rr_b);
}

static void	opr_rr(t_stack **stack_a, t_stack **stack_b, long r_a, long rr_b)
{
	if (rr_b < 0)
	{
		rr_b = -rr_b;
		while (r_a--)
			rotate_ab(stack_a, stack_b, 2);
		while (rr_b--)
			rotate_reverse_ab(stack_a, stack_b, 1);
	}
	else
	{
		while (r_a--)
			rotate_ab(stack_a, stack_b, 2);
		while (rr_b--)
			rotate_ab(stack_a, stack_b, 1);
	}
	push_ab(stack_a, stack_b, 1);
}

void	ex_ops_up(t_stack **stack_a, t_stack **stack_b, t_node *node)
{
	long	r_a;
	long	r_b;
	long	rr_b;

	r_a = node->index;
	r_b = (*stack_b)->size - node->b_node->index;
	rr_b = cal_rrotb(stack_b, node);
	if (rr_b != INT_MAX)
		opr_rr(stack_a, stack_b, r_a, rr_b);
	else
	{
		while (r_a--)
			rotate_ab(stack_a, stack_b, 0);
		while (r_b--)
			rotate_reverse_ab(stack_a, stack_b, 1);
		push_ab(stack_a, stack_b, 1);
	}
}
