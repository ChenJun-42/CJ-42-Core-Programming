/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_same_up_b_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen2 <jchen2@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 10:55:04 by jchen2            #+#    #+#             */
/*   Updated: 2025/02/02 14:50:59 by jchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ex_same_up_b_a(t_stack **stack_a, t_stack **stack_b, t_node *node)
{
	long	rr;
	long	rem_r;

	if (node->index < (node->b_node->index))
	{
		rr = node->index;
		rem_r = node->b_node->index - rr;
		while (rr--)
			rotate_ab(stack_a, stack_b, 2);
		while (rem_r--)
			rotate_ab(stack_a, stack_b, 0);
		push_ab(stack_a, stack_b, 0);
	}
	else
	{
		rr = (node->b_node->index);
		rem_r = node->index - rr;
		while (rr--)
			rotate_ab(stack_a, stack_b, 2);
		while (rem_r--)
			rotate_ab(stack_a, stack_b, 1);
		push_ab(stack_a, stack_b, 0);
	}
}
