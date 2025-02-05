/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen2 <jchen2@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 14:58:32 by jchen2            #+#    #+#             */
/*   Updated: 2025/01/06 11:30:32 by jchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	a_to_b(t_stack **stack_a, t_stack **stack_b)
{
	t_node	*node;

	node = find_ministep(stack_a);
	if (node->index <= (*stack_a)->size / 2)
	{
		if ((node->b_node->index) <= (*stack_b)->size / 2)
			ex_same_up(stack_a, stack_b, node);
		else
			ex_ops_up(stack_a, stack_b, node);
	}
	else
	{
		if ((node->b_node->index) <= (*stack_b)->size / 2)
			ex_ops_down(stack_a, stack_b, node);
		else
			ex_same_down(stack_a, stack_b, node);
	}
}
