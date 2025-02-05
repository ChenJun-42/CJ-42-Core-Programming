/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_same_down_b_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen2 <jchen2@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 10:51:33 by jchen2            #+#    #+#             */
/*   Updated: 2025/01/10 14:50:32 by jchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ex_same_down_b_a(t_stack **stack_a, t_stack **stack_b, t_node *node)
{
	long	rrr;
	long	rem_r;
	long	r_a;

	r_a = (*stack_a)->size - node->b_node->index;
	if (((*stack_b)->size - node->index) < r_a)
	{
		rrr = (*stack_b)->size - node->index;
		rem_r = r_a - rrr;
		while (rrr--)
			rotate_reverse_ab(stack_a, stack_b, 2);
		while (rem_r--)
			rotate_reverse_ab(stack_a, stack_b, 0);
		push_ab(stack_a, stack_b, 0);
	}
	else
	{
		rrr = r_a;
		rem_r = (*stack_b)->size - node->index - r_a;
		while (rrr--)
			rotate_reverse_ab(stack_a, stack_b, 2);
		while (rem_r--)
			rotate_reverse_ab(stack_a, stack_b, 1);
		push_ab(stack_a, stack_b, 0);
	}
}
