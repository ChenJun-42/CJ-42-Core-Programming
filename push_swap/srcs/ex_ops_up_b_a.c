/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_ops_up_b_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen2 <jchen2@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 10:57:06 by jchen2            #+#    #+#             */
/*   Updated: 2025/02/02 14:50:38 by jchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	cal_rrota(t_stack **stack_a, t_node *node)
{
	long	rb;
	long	ra;
	long	re_ra;
	long	val;

	rb = node->index;
	ra = (*stack_a)->size - node->b_node->index;
	val = 2 * node->b_node->index - (*stack_a)->size;
	re_ra = INT_MAX;
	if ((rb < (*stack_a)->size) && rb > val)
		re_ra = node->b_node->index - rb;
	else if (rb > (*stack_a)->size && val < (rb % (*stack_a)->size))
		re_ra = node->b_node->index - (rb % (*stack_a)->size);
	return (re_ra);
}

static void	opr_rr(t_stack **stack_a, t_stack **stack_b, long rb, long re_ra)
{
	if (re_ra < 0)
	{
		re_ra = -re_ra;
		while (rb--)
			rotate_ab(stack_a, stack_b, 2);
		while (re_ra--)
			rotate_reverse_ab(stack_a, stack_b, 0);
	}
	else
	{
		while (rb--)
			rotate_ab(stack_a, stack_b, 2);
		while (re_ra--)
			rotate_ab(stack_a, stack_b, 0);
	}
	push_ab(stack_a, stack_b, 0);
}

void	ex_ops_up_b_a(t_stack **stack_a, t_stack **stack_b, t_node *node)
{
	long	rb;
	long	ra;
	long	re_ra;

	rb = node->index;
	ra = (*stack_a)->size - node->b_node->index;
	re_ra = cal_rrota(stack_a, node);
	if (re_ra != INT_MAX)
		opr_rr(stack_a, stack_b, rb, re_ra);
	else
	{
		while (rb--)
			rotate_ab(stack_a, stack_b, 1);
		while (ra--)
			rotate_reverse_ab(stack_a, stack_b, 0);
		push_ab(stack_a, stack_b, 0);
	}
}
