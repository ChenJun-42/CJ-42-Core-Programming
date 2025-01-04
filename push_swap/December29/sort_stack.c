/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen2 <jchen2@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 16:33:07 by jchen2            #+#    #+#             */
/*   Updated: 2025/01/04 17:39:08 by jchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three_node(t_stack **stack_a, t_stack **stack_b)
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



void	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	long	size_a;
	
	if ((*stack_a)->size == 1)
		return ;
	if ((*stack_a)->size == 2)
		if ((*stack_a)->top->num > (*stack_a)->top->next->num)
			rotate_ab(stack_a, stack_b, 0);
	if ((*stack_a)->size == 3)
		sort_three_node(stack_a, stack_b);
	if ((*stack_a)->size >= 4)
	{
		push_ab(stack_a, stack_b, 1);
		push_ab(stack_a, stack_b, 1);
		size_a = (*stack_a)->size;
		while (size_a--)
		{
			renew_step_node(stack_a, stack_b);
			a_to_b(stack_a, stack_b);
		}
		b_to_a(stack_a, stack_b);
	}
}
