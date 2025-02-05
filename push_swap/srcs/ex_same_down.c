/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_same_down.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen2 <jchen2@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 10:51:33 by jchen2            #+#    #+#             */
/*   Updated: 2025/01/06 12:31:14 by jchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ex_same_down(t_stack **stack_a, t_stack **stack_b, t_node *node)
{
	long	rrr;
	long	rem_r;
	long	b_r;

	b_r = (*stack_b)->size - node->b_node->index;
	if ((*stack_a)->size - node->index < b_r)
	{
		rrr = (*stack_a)->size - node->index;
		rem_r = b_r - ((*stack_a)->size - node->index);
		while (rrr--)
			rotate_reverse_ab(stack_a, stack_b, 2);
		while (rem_r--)
			rotate_reverse_ab(stack_a, stack_b, 1);
		push_ab(stack_a, stack_b, 1);
	}
	else
	{
		rrr = (*stack_b)->size - node->b_node->index;
		rem_r = (*stack_a)->size - node->index - b_r;
		while (rrr--)
			rotate_reverse_ab(stack_a, stack_b, 2);
		while (rem_r--)
			rotate_reverse_ab(stack_a, stack_b, 0);
		push_ab(stack_a, stack_b, 1);
	}
}
