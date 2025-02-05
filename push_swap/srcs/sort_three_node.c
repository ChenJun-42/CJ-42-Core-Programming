/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_node.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen2 <jchen2@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 14:32:21 by jchen2            #+#    #+#             */
/*   Updated: 2025/01/09 14:33:35 by jchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_node(t_stack **stack_a, t_stack **stack_b)
{
	long	top;
	long	mid;
	long	bottom;

	top = (*stack_a)->top->num;
	mid = (*stack_a)->top->next->num;
	bottom = (*stack_a)->top->next->next->num;
	if (top < mid && mid > bottom && bottom > top)
	{
		rotate_reverse_ab(stack_a, stack_b, 0);
		swap_ab(stack_a, stack_b, 0);
	}
	else if (top < mid && mid > bottom && bottom < top)
		rotate_reverse_ab(stack_a, stack_b, 0);
	else if (top > mid && mid < bottom && bottom > top)
		swap_ab(stack_a, stack_b, 0);
	else if (top > mid && mid > bottom)
	{
		swap_ab(stack_a, stack_b, 0);
		rotate_reverse_ab(stack_a, stack_b, 0);
	}
	else if (top > mid && mid < bottom && bottom < top)
		rotate_ab(stack_a, stack_b, 0);
}
